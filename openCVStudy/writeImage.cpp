//�̹��� �̹����� �����غ���.
//imwrite()
//IMWRITE_JPEG_QUALITY = JPG���� ȭ��, ���� ���ϼ��� ���� ȭ��
//IMWRITE_PNG_COMPRESSION = PNG���� ȭ��, ���� ���ϼ��� ���� �뷮, �� ����ð�
//IMWRITE_PXM_BINARY = PPM, PGM ������ ���� ���� ����

#include "mainHeader.h"

using namespace std;

void writeImage() {
	cv::Mat img8 = cv::imread("../image/read_color.jpg", cv::IMREAD_COLOR);
	CV_Assert(img8.data);

	// Vector Option�� ����
	vector<int> params_jpg, params_png;
	params_jpg.push_back(cv::IMWRITE_JPEG_QUALITY); // JPGȭ������
	params_jpg.push_back(50);
	params_png.push_back(cv::IMWRITE_PNG_COMPRESSION); // PNG���෹���Τ�
	params_png.push_back(9);

	cv::imwrite("../image/write_test1.jpg", img8); // ��� �������Ϸ�
	cv::imwrite("../image/write_test2.jpg", img8, params_jpg); // �������Ϸ�
	cv::imwrite("../image/write_test.png", img8, params_png); // PNG���Ϸ�
	cv::imwrite("../image/write_test.bmp", img8); // BMP���Ϸ�
}

void writeImageTo16And32() {
	cv::Mat img8 = cv::imread("../image/read_8.tif", cv::IMREAD_COLOR); //8bit tif����
	CV_Assert(img8.data); 
	cv::Mat img16, img32;
	img8.convertTo(img16, CV_16U, 65535 / 255.0); // 65535/255.0�� uchar�� ȭ�Ұ��� ushort���� �°� ����
	img8.convertTo(img32, CV_32F, 1 / 255.0f);  // 1/255.0f�� float���� �°� 0~1 ���� ������ ����

	cv::Rect roi(100, 100, 1, 1);
	cout << "img8 Case.. " << img8(roi) << endl;
	cout << "img16 Case.. " << img16(roi) << endl;
	cout << "img32 Case.. " << img32(roi) << endl;

	cv::imwrite("../image/read_16.tif", img16);
	cv::imwrite("../image/read_32.tif", img32);
	cv::imshow("img16", img16);
	cv::imshow("img32", img32);
	cv::waitKey();
}



