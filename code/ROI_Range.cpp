#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat A = imread("C:/images/panda.jpg");
	if (A.empty()) {
		cout << "A가 없음" << endl;
	}

	imshow("Src", A);

	Mat E = A(Range::all(), Range(1, 250));
	
	imshow("Range", E);

	waitKey(0);
	return 0;
}
