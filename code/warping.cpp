#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat src = imread("C:/images/panda.jpg");
	if (src.empty()) {
		cout << "이미지를 읽을 수 없습니다." << endl;
		return -1;
	}

	int rows = src.rows;
	int cols = src.cols;
	Mat dst = src.clone();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int offset_x = (int)(25.0 * sin(2 * 3.14 * i / 180));

			if (j + offset_x >= 0 && j + offset_x < cols) {
				dst.at<Vec3b>(i, j) = src.at<Vec3b>(i, j + offset_x);
			}
			else {
				dst.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
			}
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 0;
}
