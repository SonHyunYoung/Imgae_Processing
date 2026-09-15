#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat A = imread("C:/images/panda.jpg");
	if (A.empty()) {
		cout << "A가 없음" << endl;
	}

	//Mat B = A; //얕은 복사
	Mat B = A.clone(); // 깊은 복사

	imshow("window1", A); //원본

	flip(B, B, 1); //y축 기준으로 반사
 	cout << "B만 반사시킴" << endl;

	imshow("window2", A); //flip 한 뒤 A
	imshow("window3", B); //flip 한 뒤 B

	waitKey(0);
	return 0;
}
