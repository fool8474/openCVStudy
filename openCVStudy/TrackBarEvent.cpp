//Ʈ���ٴ� ������ ���� ������ Ư�� ���� �����Ҷ� ����ϴ� ��ũ�� ��, �����̴� ��.
//createTrackbar()�Լ��� ���� ����.

#include "mainHeader.h"

using namespace std;

string title = "Ʈ���� �̺�Ʈ";
cv::Mat image;

void barOnChange(int value, void* userdata) {
	int add_value = value - 130;
	cout << "�߰� ȭ�Ұ� " << add_value << endl;
	
	cv::Mat tmp = image + add_value;
	cv::imshow(title, tmp);
}

void barTest() {
	int value = 128;
	image = cv::Mat(300, 400, CV_8UC1, cv::Scalar(120));

	cv::namedWindow(title, CV_WINDOW_AUTOSIZE);
	cv::createTrackbar("��Ⱚ", title, &value, 255, barOnChange);

	cv::imshow(title, image);
	cv::waitKey(0);
}

string bar_name = "��Ⱚ";
void barOnMouse(int event, int x, int y, int flags, void * param) {
	if (event == cv::EVENT_RBUTTONDOWN) {
		cv::add(image, 10, image);
		cv::setTrackbarPos(bar_name, title, image.at<uchar>(0));
		cv::imshow(title, image);
	} // image ��� ȭ�� 10 ����

	else if (event == cv::EVENT_LBUTTONDOWN) {
		cv::subtract(image, 10, image);
		cv::setTrackbarPos(bar_name, title, image.at<uchar>(0));
		cv::imshow(title, image);
	} // image ��� ȭ�� 10 ��
}

void barMouseTest() {
	int value = 130;
	image = cv::Mat(300, 500, CV_8UC1, cv::Scalar(120));
	cv::namedWindow(title, CV_WINDOW_AUTOSIZE);
	cv::createTrackbar(bar_name, title, &value, 255, barOnChange); //Ʈ���� ���
	cv::setMouseCallback(title, barOnMouse, 0); //���콺 �ݹ��Լ� ���

	cv::imshow(title, image);
	cv::waitKey(0);
} //���콺 �ݹ��Լ��� Ʈ���� ������ ���� ��ȣ�ۿ����� �ʴ´�. �̸� �ذ��Ϸ��� ��� �ؾ��ұ�?
