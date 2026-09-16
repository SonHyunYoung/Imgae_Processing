#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img, roi, clone; //이미지  Mat 클래스
int mx1, my1, mx2, my2; //마우스 좌표 저장
bool cropping = false; //그림을 그릴지 말지 관련한 변수

//마우스 이벤트 발생할때 작동하는 함수
void onMouse(int event, int x, int y, int flages, void* params) {
	if (event == EVENT_LBUTTONDOWN) { //왼쪽 버튼 클릭
		img = clone.clone(); //clone을 통해 새 화면을 가져옴(이전에 그린 사각형 지우기 위함)
		imshow("image", img); //다시 원본 이미지가 보여짐
		
		//처음 클릭 위치 지정
		mx1 = x;
		my1 = y;

		//사각형 그리는거 true
		cropping = true; 
	}
	else if (event == EVENT_MOUSEMOVE && cropping == true) { //마우스 움직일때 사각형이 따라오게 하는 부분
		//사각형 끝점 위치 저장
		mx2 = x;
		my2 = y;

		img = clone.clone(); //사각형 영역을 계속해서 표현하기 위해,원본 이미지 가져옴
		 
		rectangle(img, Rect(Point(mx1, my1), Point(mx2, my2)), Scalar(0, 255, 0), 2); //사각형 그리는 함수, Point 이용해서 어느 방향으로 그리든 문제 없게 함

		imshow("image", img); //사각형이 마우스를 따라오는걸 계속 띄움
	}
	else if (event == EVENT_LBUTTONUP) {

		//마우스 마지막 위치 저장
		mx2 = x;
		my2 = y;

		img = clone.clone(); //원본 이미지 가져옴

		cropping = false; //사각형 더 안그리게 함

		rectangle(img, Rect(Point(mx1, my1), Point(mx2, my2)), Scalar(0, 255, 0), 2); //사각형 그리는 함수, Point 이용해서 어느 방향으로 그리든 문제 없게 함

		imshow("image", img); //사각형 위치 확정된 그림 띄움
	}
}

int main() {
	img = imread("C:/images/panda.jpg");
	imshow("image", img); //이미지 띄움
	clone = img.clone(); //원본 이미지 저장

	setMouseCallback("image", onMouse); //마우스 이벤트 발생시 콜백 함수

	while (1) {
		int key = waitKey(100); //100ms 마다 키 입력 체크? 

		if (key == 'q') { //q 입력 시 프로그램 종료
			break;
		}
		else if (key == 'c') { //c 입력 시 관심 영역 크롭 후 저장
			Rect box(Point(mx1, my1), Point(mx2, my2)); 

			if (box.width > 0 && box.height > 0) {
				roi = clone(box);
				imshow("result", roi); //크롭한 경과 보여줌
				imwrite("C:/images/result.jpg", roi); //크롭한 결과 저장

			}
			else {
				cout << "지정된 영역이 없습니다." << endl;
			}
		}
	}

	return 0;

}
