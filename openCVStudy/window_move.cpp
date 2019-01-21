#include "mainHeader.h"

using namespace std;

void helloWindow() {
	cv::Mat image1(300, 400, CV_8U, cv::Scalar(255)); //������� ���� ����
	cv::Mat image2(300, 400, CV_8U, cv::Scalar(100)); //ȸ������ ���� ����
	string title1 = "white â ����";
	string title2 = "gray â ����";

	cv::namedWindow(title1, cv::WINDOW_AUTOSIZE);
	cv::namedWindow(title2, cv::WINDOW_NORMAL); // �̸� ���� ��, ������ ����. 
	//WINDOW_AUTOSIZE : �� 1, ǥ���� ��� ũ�⿡ ���� �ڵ� ����
	//WINDOW_NORMAL : �� 0, ������ ũ���� ������ ����
	//WINDOW_OPENGL : �� 8, OpenGL�� �����ϴ� ������ ����

	cv::moveWindow(title1, 10, 10); //�����Ҷ� ��ġ
	cv::moveWindow(title2, 500, 500);

	cv::imshow(title1, image1); //��� ���Ҹ� �������� ǥ��
	cv::imshow(title2, image2);
	cv::waitKey(); //Ű���� �̺�Ʈ�� ��� : �Է½� ��������
	
	cv::resizeWindow(title1, 300, 800); //������ �缳��
	cv::resizeWindow(title2, 800, 300);
	cv::waitKey();

	cv::moveWindow(title1, 110, 110); //�����Ҷ� ��ġ
	cv::moveWindow(title2, 550, 550);
	cv::waitKey();

	cv::destroyAllWindows(); //��� ���� ������ ����
}