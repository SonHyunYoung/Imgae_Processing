#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat src = imread("C:/images/panda.jpg", 1);
	Mat dst;
	imshow("src", src);

	for (int i = 1; i < 61; i = i + 2) {
		GaussianBlur(src, dst, Size(i, i), 0, 0);
		imshow("Gaussian filter", dst);
	}

	waitKey(0);
	return 0;
}
