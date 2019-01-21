// OpenCV에서는 사각형, 직선, 원 등을 그리는 함수를 제공
// void line(Mat & img, Point pt1, Point pt2, const Scalar& color, int thickness = 1, int lineType = 8, int shift = 0)
// void rectangle(Mat & img, Point pt1, Point pt2, const Scalar& color, int thickness = 1, int lineType = 8, int shift = 0)
// void rectangle(Mat & img, Rect rec, const Scalar& color, int thickness = 1, int lineType = 8, int shift = 0)
// lineType에서 LINE_4 = 4방향 연결선, LINE_8 = 8방향 연결선, LINE_AA = 계단현상 감소 선
// shift는 입력 좌표에 대해 오른쪽으로 비트시프트 연산한 결과를 좌표로 지정해서 직선을 그리게 된다.

#include "mainHeader.h"
#include "drawLineRect.h"
using namespace std;

void drawLineRect() {
	cv::Scalar blue(255, 0, 0), red(0, 0, 255), green(0, 255, 0);
	cv::Scalar white = cv::Scalar(255, 255, 255);
	cv::Scalar yellow(0, 255, 255);
	//Scalar들을 미리 지정해서 페인트통을 만들어놓자.

	cv::Mat image(400, 600, CV_8UC3, white);
	cv::Point pt1(50, 130), pt2(200, 300), pt3(300, 150), pt4(400, 50);
	cv::Rect rect(pt3, cv::Size(200, 150));

	cv::line(image, pt1, pt2, red); //50, 130, 200, 300, 빨간색 선
	cv::line(image, pt3, pt4, green, 2, cv::LINE_AA); //300, 150, 400, 50, 녹색 선, 안티에일리싱
	cv::line(image, pt3, pt4, green, 3, cv::LINE_8, 1); // 300, 150, 400, 50, 1쉬프트, 녹색 선, 8방향

	cv::rectangle(image, rect, blue, 2); // 300, 150, 500, 300 굵기2
	cv::rectangle(image, rect, blue, cv::FILLED, cv::LINE_4, 1); // 300, 150, 500, 300, 1쉬프트, 굵기1, 채워짐, 4방향
	cv::rectangle(image, pt1, pt2, red, 3); // 50, 130, 200, 300, 빨간색, 굵기3

	cv::imshow("직선 & 사각형", image);
	cv::waitKey(0);
}

//Font 그리기, putText()
//img, text, org, fontFace, fontScale, color, thickness=1, lineType=8, bottomLeftOrigin=false
//bottomLeftOrigin : 영상의 원점 좌표를 하단 왼쪽으로 설정 (기본 : 상단 왼쪽)


void drawFont() {
	cv::Scalar olive(128, 128, 0), violet(221, 160, 221), brown(42, 42, 165);
	cv::Point pt1(20, 100), pt2(20, 200), pt3(30, 250);
	cv::Mat image(300, 500, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::putText(image, "SIMPLEX", cv::Point(20, 30), cv::FONT_HERSHEY_SIMPLEX, 1, brown); // 크기 1, SIMPLEX 글씨체, 20,30 시작
	cv::putText(image, "DUPLEX", pt1, cv::FONT_HERSHEY_DUPLEX, 2, olive);
	cv::putText(image, "TRIPLEX", pt2, cv::FONT_HERSHEY_TRIPLEX, 3, violet);
	cv::putText(image, "ITALIC", pt3, cv::FONT_HERSHEY_PLAIN | cv::FONT_ITALIC, 2, violet); // 크기 2, PLAIN 글씨체, 기울게
	cv::putText(image, "한글테스트", cv::Point(100, 100), cv::FONT_HERSHEY_DUPLEX, 2, olive); // 한글 작동하지 않음

	cv::imshow("글자쓰기", image);
	cv::waitKey(0);
}
