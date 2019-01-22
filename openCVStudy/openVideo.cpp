// HIGHGUI ���̺귯���� ������ ó���� ����

// VideoCapture() ������
// open() ����
// isOpened()
// release() ���� ����
// get() ������ �Ӽ��� �� ��ȯ
// set() �Ӽ� ����
// grab() ���� ������ ���
// retrieve() grab()���� ���� ������ ���ڵ��� image�� ����
// read(), >> ���� ������ ���ڵ�, image��ķ� ����. (grab, retrieve ���� ����)

// VideoWriter() ������
// open() ����
// isOpened()
// write() ����

// ī�޶� �Ӽ� �ĺ���
// CAP_PROP_...
// POS_MSEC ���� ��ġ
// POS_FRAMES ĸó�Ǵ� ������ ��ȣ
// POS_AVI_RATIO ����� ��ġ (0~1)
// FRAME_WIDTH ������ �ʺ�
// FRAME_HEIGHT ������ ����
// FPS �ʴ� ������
// FOURCC �ڵ� 4����
// FRAME_COUNT �� ������ ��
// MODE Mat���� ����
// AUTOFOCUS �ڵ� ���� ����

// �ڵ� ����
// CV_FOURCC_PROMPT �ڵ� ���� ��ȭâ ���

#include "mainHeader.h"
using namespace std;

cv::VideoCapture capture;


void put_string(cv::Mat &frame, std::string text, cv::Point pt, int value) {
	text += to_string(value);
	cv::Point shade = pt + cv::Point(2, 2);
	int font = cv::FONT_HERSHEY_SIMPLEX;
	putText(frame, text, shade, font, 0.7, cv::Scalar(0, 0, 0), 2);
	putText(frame, text, pt, font, 0.7, cv::Scalar(120, 200, 90), 2);
} //�׸��� ȿ���� ���� ���� �ֱ�


void helloVideo() {
	capture.open("../video/sample.mp4");
	if (!capture.isOpened()) {
		cout << "ī�޶� ������� �ʾҽ��ϴ�." << endl;
		cv::waitKey();
		exit(1);
	}

	cout << "�ʺ� : " << capture.get(cv::CAP_PROP_FRAME_WIDTH) << endl;
	cout << "���� : " << capture.get(cv::CAP_PROP_FRAME_HEIGHT) << endl;
	cout << "���� : " << capture.get(cv::CAP_PROP_EXPOSURE) << endl;
	cout << "��� : " << capture.get(cv::CAP_PROP_BRIGHTNESS) << endl;

	for (;;) {
		cv::Mat frame;
		capture.read(frame);

		put_string(frame, "EXPOS: ", cv::Point(10, 40), capture.get(cv::CAP_PROP_EXPOSURE)); // ����� EXPOS ����
		imshow("ī�޶� ���󺸱�", frame);
		if (cv::waitKey(30) >= 0) break;
	}
}


void zoom_bar(int value, void*) {
	capture.set(cv::CAP_PROP_ZOOM, value); // zoom ����
}

void focus_bar(int value, void*) {
	capture.set(cv::CAP_PROP_FOCUS, value); // focus ����
}

void setCamera() {
	capture.open("../video/sample.mp4"); // ��� ��ü ���� ī�޶� 0���� �����ؼ� ����ؾ� �ٲ� (capture.open(0))
	CV_Assert(capture.isOpened());

	capture.set(cv::CAP_PROP_FRAME_WIDTH, 400); // ī�޶� ������ �ʺ�
	capture.set(cv::CAP_PROP_FRAME_HEIGHT, 300);
	capture.set(cv::CAP_PROP_AUTOFOCUS, 0); // ������Ŀ�� ����
	capture.set(cv::CAP_PROP_BRIGHTNESS, 150); // ������ ��� �ʱ�ȭ

	int zoom = capture.get(cv::CAP_PROP_ZOOM); // ī�޶� �Ӽ� ��������
	int focus = capture.get(cv::CAP_PROP_FOCUS);

	string title = "ī�޶� �Ӽ�����"; // ������ �̸� ����
	cv::namedWindow(title); // ������ ����
	cv::createTrackbar("zoom", title, &zoom, 10, zoom_bar); // ������ �� Ʈ����
	cv::createTrackbar("focus", title, &focus, 40, focus_bar); // ������ ��Ŀ�� Ʈ����
	
	for (;;) {
		cv::Mat frame; // ī�޶� ����ޱ�
		capture >> frame;

		put_string(frame, "zoom : ", cv::Point(10, 240), zoom);
		put_string(frame, "focus : ", cv::Point(10, 270), focus);

		cv::imshow(title, frame);
		if (cv::waitKey(30) >= 0) break;
	}
}













