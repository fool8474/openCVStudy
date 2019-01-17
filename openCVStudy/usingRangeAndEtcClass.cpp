#include "mainHeader.h"

// Range : �ϳ��� ���������� ���ӵǴ� ���� �������� ����
// Mat Ŭ�������� �� �Ǵ� ���� ������ ������ �� ���
// [Start, End)�� �Ű����� ���

void rangeChanger(int xStart, int xEnd, int yStart, int yEnd, int changeInt, cv::Mat targetMat) {
	cv::Range r1(xStart, xEnd), r2(yStart, yEnd);
	matPrinter(targetMat);
	std::cout << "Range is ... : " << r1 << r2 << std::endl << std::endl;

	cv::Mat rangeMat = targetMat(r1, r2);

	matPrinter(rangeMat);
	rangeMat.setTo(changeInt);
	matPrinter(rangeMat);
	matPrinter(targetMat);
}

void matPrinter(cv::Mat targetMat) {
	std::cout << "this Mat is... : " << targetMat << std::endl << std::endl;
}

void rangeTest() {
	cv::Mat curMat(6, 6, CV_32S);
	curMat.setTo(15);
	rangeChanger(3, 5, 2, 5, 11, curMat);

	return;
}

// ROI�� ����, ����ϴ� �޼ҵ��

void print_locateROI(std::string str, cv::Mat m) {
	cv::Size size;
	cv::Point pt;
	m.locateROI(size, pt); // �θ��� ������, �׸��� ���� pt�� �ִ´�.
	std::cout << "�θ�ũ�� " << size << ", ";
	std::cout << "[" << str << "] = ";
	std::cout << m.size() << " from" << pt << std::endl;
}

void ROIMethod() {
	cv::Range r1(0, 3), r2(3, 7);
	int data[] = {
		10,11,12,13,14,15,16,
		20,21,22,23,24,25,26,
		30,31,32,33,34,35,36,
		40,41,42,43,44,45,46,
	};

	cv::Mat m1(5, 7, CV_32S, data);
	cv::Mat m2 = m1(r1, r2);
	cv::Mat m3 = m1(r1, r1);

	print_locateROI("m2", m2);
	print_locateROI("m3", m3);

	m2.adjustROI(-1, 1, 2, -1); // Range�� ������ ����
	m3.adjustROI(0, -1, -2, 2);

	std::cout << "���ɿ��� ����" << std::endl;

	print_locateROI("m2", m2);
	print_locateROI("m3", m3);

	std::cout << std::endl;
	std::cout << m2 << std::endl;
	std::cout << m3 << std::endl;
}


/*
��Ÿ �޼ҵ��

Mat ��ü ���� �߰� & ���� : push_back(), pop_back()
Mat ��ü ���� : release()
Mat ��ü ����� : t()
*/

//push back�� ���, �迭, �Ϲ��ڷ����� ���Ҹ� ���� ����. ���(Mat)�϶��� �ڷ����� �� ���� ��ġ�� �ʿ�.
//pop back�� ������ ��ġ���� ���ҵ� ����. (���� �������!)
//release�� ����� ��ü��Ų��. ���� �ı��� �۵��� �ڵ� ȣ��ȴ�.

void invTMul() {
	float data[] = { 1,0,2, -3,4,6, -1,-2,3 };
	cv::Mat m1(3,3, CV_32F, data);
	cv::Mat m2(cv::Matx13f(6, 30, 8)); // shape(3,1), data(6,30,8)�� ���, y���� �ȴ�.
	cv::Mat m2_t = m2.t(); // 

	cv::Mat m1_inv = m1.inv(cv::DECOMP_LU); //����� ���
	cv::Mat x = m1_inv * m2_t; //��� ��
	
	std::cout << "[m1] = " << std::endl << m1 << std::endl;
	std::cout << "[m1_int] = " << std::endl << m1_inv << std::endl;
	std::cout << "[x] = " << std::endl << x << std::endl;

	std::cout << "������������ �� x1, x2, x3 = " << x.t() << std::endl << std::endl;
}