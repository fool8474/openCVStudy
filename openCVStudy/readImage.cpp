// �̹��� ���� ó��
// imread()�� filename, flags�� �Ű������� ����. flag�� �÷�Ÿ���� �ǹ��Ѵ�.
// IMREAD_UNCHANGED = -1 , ������ ������ �÷������� ��ȯ (alpha ����)
// IMREAD_GRAYSCALE = 0  , grayscale �������� ��ȯ
// IMREAD_COLOR     = 1  , color �������� ��ȯ
// IMREAD_ANYDEPTH  = 2  , �Է� ���Ͽ� ���ǵ� ���̿� ���� 16/32��Ʈ �������� ��ȯ. ���� X��� 8��Ʈ��.
// IMREAD_ANYCOLOR  = 4  , ���Ͽ� ���ǵ� Ÿ������ ��ȯ
// imwrite()�� img����� �������� �����Ѵ�. filename, img, params�� �ִ�. img�� �ش� Mat, params�� ���� ��Ŀ� ���Ǵ� �μ� �ֵ��� ����.

#include "mainHeader.h"

using namespace std;

void print_MatInfo(std::string name, cv::Mat img) {
	string mat_type;
	if (img.depth() == CV_8U) mat_type = "CV_8U";
	else if (img.depth() == CV_8S) mat_type = "CV_8S";
	else if (img.depth() == CV_16U) mat_type = "CV_16U";
	else if (img.depth() == CV_16S) mat_type = "CV_16S";
	else if (img.depth() == CV_32S) mat_type = "CV_32S";
	else if (img.depth() == CV_32F) mat_type = "CV_32F";
	else if (img.depth() == CV_64F) mat_type = "CV_64F";

	cout << name;
	cout << ": depth(" << img.depth() << ") channels(" << img.channels() << ") -> �ڷ��� : ";
	cout << mat_type << "C" << img.channels() << endl;
}

void imgReader() {
	string filename = "../image/read_gray.jpg";
	cv::Mat gray2gray = cv::imread(filename, cv::IMREAD_GRAYSCALE); // 8UC1 grayscale�� �ҷ���
	cv::Mat gray2color = cv::imread(filename, cv::IMREAD_COLOR); // 8UC3 color�� �ҷ���
	CV_Assert(gray2gray.data && gray2color.data); // ������ ���������� �ε���� ������ ����

	cv::Rect roi(100, 100, 1, 1);
	cout << "��� ��ǥ (100,100) ȭ�Ұ� " << endl; // 97, (97,97,97)
	cout << "gray2gray " << gray2gray(roi) << endl;
	cout << "gray2color " << gray2color(roi) << endl << endl; // ����� 1�� rect�� �ҷ������ν� 1�ȼ� ���

	print_MatInfo("gray2gray", gray2gray);
	print_MatInfo("gray2color", gray2color);
	cv::imshow("gray2gray", gray2gray);
	cv::imshow("gray2color", gray2color);
	cv::waitKey(0);
}

// �̹��� color ���� �ٷﺸ��

void imgReaderColor() {
	string filename = "../image/read_color.jpg";
	cv::Mat color2gray = cv::imread(filename, cv::IMREAD_GRAYSCALE);
	cv::Mat color2color = cv::imread(filename, cv::IMREAD_COLOR);
	CV_Assert(color2gray.data && color2color.data);
	
	cv::Rect roi(100, 100, 1, 1);
	cout << "��� ��ǥ (100,100) ȭ�Ұ� " << endl; // 27, (78, 31, 0)
	cout << "color2gray " << color2gray(roi) << endl; 
	cout << "color2color " << color2color(roi) << endl << endl; // ����� 1�� rect�� �ҷ������ν� 1�ȼ� ���

	print_MatInfo("color2gray", color2gray);
	print_MatInfo("color2color", color2color);
	cv::imshow("color2gray", color2gray);
	cv::imshow("color2color", color2color);
	cv::waitKey(0);
}


// tif������ 16��Ʈ �̻��� ����. 16��Ʈ �̻��� ������ �޾ƺ���

void tifImageReader() {
	string filename1 = "../image/read_32.tif";
	cv::Mat color2unchanged1 = cv::imread(filename1, cv::IMREAD_UNCHANGED);
	CV_Assert(color2unchanged1.data);

	cv::Rect roi(100, 100, 1, 1);
	cout << "16��Ʈ �̻� ���� ��� ��ǥ (100,100) ȭ�Ұ� " << endl;
	cout << "color2unchanged1 " << color2unchanged1(roi) << endl << endl; // ����� 1�� rect�� �ҷ������ν� 1�ȼ� ���

	print_MatInfo("color2unchanged1", color2unchanged1);
	cv::imshow("color2unchanged1", color2unchanged1);
	cv::waitKey(0);
}

