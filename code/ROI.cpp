#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat A = imread("C:/images/panda.jpg");
	if (A.empty()) {
		cout << "A가 없음" << endl;
	}

	Rect r(10, 10, 100, 100);
	Mat D = A(r); //얕은 복사
	//Mat D = A(r).clone(); //깊은 복사
	D = Scalar(0, 255, 255);
	
	imshow("Src", A);
	imshow("ROI", D);

	waitKey(0);
	return 0;
}
