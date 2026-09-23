#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat src1, dst;
	double gamma = 0.75; //1보다 크면 사진이 어두워 지고 1보다 작으면 사진이 밝아진다.

	src1 = imread("C:/images/puppy.jpg"); 

	if (src1.empty()) {
		cout << "영상을 읽을 수 없습니다." << endl;
		return -1;
	}

	resize(src1, src1, Size(340, 460)); //사진 크기 조정

	Mat table(1, 256, CV_8U);
	uchar *p = table.ptr();

	for (int i = 0; i < 256; i++) {
		p[i] = saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);
	}

	LUT(src1, table, dst);
	imshow("src1", src1);
	moveWindow("src1", 200, 200); //사진 뜨는 위치 지정
	imshow("dst", dst);
	
	waitKey(0);
	return 0;
}
