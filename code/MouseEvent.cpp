#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void* params) { //마우스 클릭이 발생했을 때 그 위치에 원을 그리고, 원 밑에 글씨를 배치함
	if (event == EVENT_LBUTTONDOWN) {
		Mat& img = *(Mat*)(params); //main에서 선언한 src 주소 가져와서 똑같이 할당
		circle(img, Point(x, y), 50, Scalar(0, 255, 0), 10);
		putText(img, "I found a Panada!", Point(x, y + 50), FONT_HERSHEY_PLAIN, 1.0, 255, 2);
		imshow("src", img); //원과 글씨 그린후 다시 사진 띄어줌
	}
	else if (event == EVENT_RBUTTONDOWN) {}
	else if (event == EVENT_MBUTTONDOWN) {}
	else if (event == EVENT_MOUSEMOVE) {}
}

int main() {
	Mat src = imread("C:/images/panda.jpg", IMREAD_COLOR); 
	
	if (src.empty()) {
		cout << "영상을 읽을 수 없음" << endl;
	}

	imshow("src", src);

	setMouseCallback("src", onMouse, &src); //콜백 함수, src에서 마우스 이벤트가 발생하면 onMouse 함수를 실행시킴
	waitKey(0);
	return 0;
}
