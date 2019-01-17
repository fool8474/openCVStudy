// �̺�Ʈ�� ó���غ���.
// �ݹ� �Լ� : �Ϲ������� �̺�Ʈ�� ó���ϱ� ���� �Լ�.
// Ű���� ó���� OpenCV�� waitkey()�� ����. :: Ű �̺�Ʈ�� �ش��ϴ� �������� ���� ��ȯ

#include "mainHeader.h"
#include "cvEventControl.h"

using namespace std;

void keyEventTester() {
	cv::Mat image(200, 300, CV_8U, cv::Scalar(255));
	cv::namedWindow("Ű���� �̺�Ʈ", CV_WINDOW_AUTOSIZE);
	cv::imshow("Ű���� �̺�Ʈ", image);

	while (1) {
		//int key = cv::waitKey(100); //100ms���� Ű�̺�Ʈ ���
		//���� waitKey�� ����ϸ� �ǳ�, ȭ��ǥ�� �۵��� �ȵǴ���.
		//���� waitKeyEx()�� ����غ���. �� �ȴ�!

		int key = cv::waitKeyEx(100);
		if (key == 27) break; //ESC
		
		switch (key) {
		case 'a': cout << "aŰ �Է�" << endl; break;
		case 'b': cout << "bŰ �Է�" << endl; break;
		case 0x41: cout << "AŰ �Է�" << endl; break;
		case 66: cout << "BŰ �Է�" << endl; break;
		case 0x250000: cout << "���� ȭ��ǥ Ű �Է�" << endl; break;
		case 0x260000: cout << "���� ȭ��ǥ Ű �Է�" << endl; break;
		case 0x270000: cout << "������ ȭ��ǥ Ű �Է�" << endl; break;
		case 0x280000: cout << "�Ʒ��� ȭ��ǥ Ű �Է�" << endl; break;
		}
	}
}

void mouseEventTester() {
	cv::Mat image(200, 300, CV_8U);
	image.setTo(255);
	cv::imshow("���콺 �̺�Ʈ1", image);
	cv::imshow("���콺 �̺�Ʈ2", image);

	cvSetMouseCallback("���콺 �̺�Ʈ1", onMouse, 0); //���콺�̺�Ʈ1�� onMoue callBack�� �߰��Ѵ�.
	//cvSetMouseCallback("���콺 �̺�Ʈ2", onMouse, 0); //���콺�̺�Ʈ2�� ���, �׷��� ������.
	cv::waitKey(0);
}

void onMouse(int event, int x, int y, int flags, void * param) {
	switch (event) {

	case CV_EVENT_LBUTTONDOWN :
		cout << "���콺 ���ʹ�ư ������" << endl;
		break;

	case CV_EVENT_RBUTTONDOWN :
		cout << "���콺 ������ ��ư ������" << endl;
		break;

	case CV_EVENT_RBUTTONUP :
		cout << "���콺 ������ ��ư ����" << endl;
		break;

	case CV_EVENT_LBUTTONDBLCLK :
		cout << "���콺 ���ʹ�ư ����Ŭ��" << endl;
		break;

	}
}

