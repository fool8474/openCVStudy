//트랙바는 일정한 범위 내에서 특정 값을 선택할때 사용하는 스크롤 바, 슬라이더 바.
//createTrackbar()함수를 통해 생성.

#include "mainHeader.h"

using namespace std;

string title = "트랙바 이벤트";
cv::Mat image;

void barOnChange(int value, void* userdata) {
	int add_value = value - 130;
	cout << "추가 화소값 " << add_value << endl;
	
	cv::Mat tmp = image + add_value;
	cv::imshow(title, tmp);
}

void barTest() {
	int value = 128;
	image = cv::Mat(300, 400, CV_8UC1, cv::Scalar(120));

	cv::namedWindow(title, CV_WINDOW_AUTOSIZE);
	cv::createTrackbar("밝기값", title, &value, 255, barOnChange);

	cv::imshow(title, image);
	cv::waitKey(0);
}

string bar_name = "밝기값";
void barOnMouse(int event, int x, int y, int flags, void * param) {
	if (event == cv::EVENT_RBUTTONDOWN) {
		cv::add(image, 10, image);
		cv::setTrackbarPos(bar_name, title, image.at<uchar>(0));
		cv::imshow(title, image);
	} // image 모든 화소 10 더함

	else if (event == cv::EVENT_LBUTTONDOWN) {
		cv::subtract(image, 10, image);
		cv::setTrackbarPos(bar_name, title, image.at<uchar>(0));
		cv::imshow(title, image);
	} // image 모든 화소 10 뺌
}

void barMouseTest() {
	int value = 130;
	image = cv::Mat(300, 500, CV_8UC1, cv::Scalar(120));
	cv::namedWindow(title, CV_WINDOW_AUTOSIZE);
	cv::createTrackbar(bar_name, title, &value, 255, barOnChange); //트랙바 등록
	cv::setMouseCallback(title, barOnMouse, 0); //마우스 콜백함수 등록

	cv::imshow(title, image);
	cv::waitKey(0);
} //마우스 콜백함수와 트랙바 조정이 서로 상호작용하지 않는다. 이를 해결하려면 어떻게 해야할까?
