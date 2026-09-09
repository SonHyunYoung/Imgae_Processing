#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
  Mat src = imread("이미지 경로", IMREAD_COLOR) //이미지 읽어옴 

  if(src.empty()){
    cout << "영상 파일을 읽을 수 없습니다" << endl;
  }

imshow("src", src); //그림 띄움

Mat gray, edge, output; //영상을 저장할 Mat 객체, 각각 그레이 스케일, 엣지, 출력물
cvtColor(src, gray, COLOR_BGR2GRAY); //cvtColor ==> 색상 변환
imwrite("저장할경로/gray.jpg", gray); //흑백으로 만든 사진 저장 

waitKey(0);
return 0;
}
