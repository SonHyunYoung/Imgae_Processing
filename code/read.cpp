#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
  Mat image; //이미지 파일 행렬로 읽어옴
  image = imread("이미지 경로", IMREAD_COLORED); //이미지 컬러로 읽어옴

  if(image.empty()){ //이미지 존재하지 않는 경우
    cout << "영상을 읽을 수 없음" << endl;
  }

  imshow("출력 영상", image); //이미지 출력

  waitKey(0);
  return 0;
}
