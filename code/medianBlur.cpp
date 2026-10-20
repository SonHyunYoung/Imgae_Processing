#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat src = imread("C:/images/panda.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) {
		return -1;
	}
	Mat dst1, dst2;

	Mat noise_img = Mat::zeros(src.rows, src.cols, CV_8U);
	randu(noise_img, 0, 255);

	Mat black_img = noise_img < 10;
	Mat white_img = noise_img > 245;

	Mat src1 = src.clone();
	src1.setTo(255, white_img);
	src1.setTo(0, black_img);

	medianBlur(src1, dst1, 3);
	medianBlur(src1, dst2, 5);

	imshow("original", src);
	imshow("source", src1);
	imshow("result1", dst1);
	imshow("result2", dst2);

	waitKey(0);
	return 0;
}
