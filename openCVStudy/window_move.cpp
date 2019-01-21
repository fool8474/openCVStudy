#include "mainHeader.h"

using namespace std;

void helloWindow() {
	cv::Mat image1(300, 400, CV_8U, cv::Scalar(255)); //흰색바탕 영상 생성
	cv::Mat image2(300, 400, CV_8U, cv::Scalar(100)); //회색바탕 영상 생성
	string title1 = "white 창 제어";
	string title2 = "gray 창 제어";

	cv::namedWindow(title1, cv::WINDOW_AUTOSIZE);
	cv::namedWindow(title2, cv::WINDOW_NORMAL); // 이름 설정 후, 윈도우 생성. 
	//WINDOW_AUTOSIZE : 값 1, 표지될 행렬 크기에 맞춰 자동 설정
	//WINDOW_NORMAL : 값 0, 윈도우 크기의 재조정 가능
	//WINDOW_OPENGL : 값 8, OpenGL을 지원하는 윈도우 생성

	cv::moveWindow(title1, 10, 10); //시작할때 위치
	cv::moveWindow(title2, 500, 500);

	cv::imshow(title1, image1); //행렬 원소를 영상으로 표시
	cv::imshow(title2, image2);
	cv::waitKey(); //키보드 이벤트를 대기 : 입력시 다음으로
	
	cv::resizeWindow(title1, 300, 800); //사이즈 재설정
	cv::resizeWindow(title2, 800, 300);
	cv::waitKey();

	cv::moveWindow(title1, 110, 110); //시작할때 위치
	cv::moveWindow(title2, 550, 550);
	cv::waitKey();

	cv::destroyAllWindows(); //모든 열린 윈도우 제거
}