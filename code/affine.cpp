#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat src = imread("C:/images/panda.jpg");
	Mat dst = Mat();

	int tx = 100;
	int ty = 20;

	Mat tmat = Mat::eye(2, 3, CV_64F);   // [1 0 0; 0 1 0]
	tmat.at<double>(0, 2) = tx;
	tmat.at<double>(1, 2) = ty;

	warpAffine(src, dst, tmat, src.size());

	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 0;
}
