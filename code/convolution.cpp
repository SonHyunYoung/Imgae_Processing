#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image = imread("C:/images/panda.jpg");

	if (image.empty()) return -1; // 안전을 위한 예외 처리

	float weight[] = {
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F,
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F,
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F
	};

	Mat mask(3, 3, CV_32F, weight);
	Mat blur1, blur2, blur3, blur4;

	filter2D(image, blur1, -1, mask, Point(-1, -1), 0, BORDER_CONSTANT);
	filter2D(image, blur2, -1, mask, Point(-1, -1), 0, BORDER_REPLICATE);
	filter2D(image, blur3, -1, mask, Point(-1, -1), 0, BORDER_REFLECT);
	//filter2D(image, blur4, -1, mask, Point(-1, -1), 0, BORDER_WRAP);

	imshow("image", image);
	imshow("CONSTANT", blur1);
	imshow("REPLICATE", blur2);
	imshow("REFLECT", blur3);
	//imshow("WRAP", blur4);

	waitKey(0);
	return 0;
}
