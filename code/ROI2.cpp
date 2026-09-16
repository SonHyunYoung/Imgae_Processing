#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat A = imread("C:/images/panda.jpg");
	Mat B = imread("C:/images/logo.jpg");

	//로고(B)의 크기를 가로 150, 세로 150으로 줄임
	resize(B, B, Size(150, 150));

	Mat roi(A, Rect(A.cols - B.cols, A.rows - B.rows, B.cols, B.rows));
	B.copyTo(roi);

	imshow("result", A);

	waitKey(0);
	return 0;
}
