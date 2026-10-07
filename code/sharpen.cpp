#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat src = imread("C:/images/panda.jpg", IMREAD_COLOR);
	if (src.empty()) {
		return -1;
	}

	imshow("src", src);

	Mat dst1, dst2, dst3, dst4;
	float weight1[9] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };
	float weight2[9] = { -1, -1, -1, -1, 8, -1, -1, -1, -1 };
	float weight3[9] = { -1, -1, -1, -1, 10, -1, -1, -1, -1 };

	Mat mask1 = Mat(3, 3, CV_32F, weight1);
	Mat mask2 = Mat(3, 3, CV_32F, weight2);
	Mat mask3 = Mat(3, 3, CV_32F, weight3);

	filter2D(src, dst1, -1, mask1, Point(-1, -1), 0, BORDER_DEFAULT);
	filter2D(src, dst2, -1, mask2, Point(-1, -1), 0, BORDER_DEFAULT);
	filter2D(src, dst3, -1, mask3, Point(-1, -1), 0, BORDER_DEFAULT);

	imshow("sharpen", dst1);
	imshow("edge", dst2);
	imshow("bright sharpen", dst3);


	waitKey(0);
	return 0;
}
