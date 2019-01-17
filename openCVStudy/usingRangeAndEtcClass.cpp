#include "mainHeader.h"

// Range : 하나의 시퀀스에서 연속되는 서브 시퀀스를 지정
// Mat 클래스에서 행 또는 열의 범위를 지정할 떄 사용
// [Start, End)의 매개변수 사용

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

// ROI를 조정, 출력하는 메소드들

void print_locateROI(std::string str, cv::Mat m) {
	cv::Size size;
	cv::Point pt;
	m.locateROI(size, pt); // 부모의 사이즈, 그리고 시작 pt를 넣는다.
	std::cout << "부모크기 " << size << ", ";
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

	m2.adjustROI(-1, 1, 2, -1); // Range의 범위를 조정
	m3.adjustROI(0, -1, -2, 2);

	std::cout << "관심영역 변경" << std::endl;

	print_locateROI("m2", m2);
	print_locateROI("m3", m3);

	std::cout << std::endl;
	std::cout << m2 << std::endl;
	std::cout << m3 << std::endl;
}


/*
기타 메소드들

Mat 객체 원소 추가 & 삭제 : push_back(), pop_back()
Mat 객체 해제 : release()
Mat 객체 역행렬 : t()
*/

//push back은 행렬, 배열, 일반자료형의 원소를 삽입 가능. 행렬(Mat)일때는 자료형과 열 개수 일치할 필요.
//pop back은 마지막 위치에서 원소들 제거. (행이 사라진다!)
//release는 행렬을 해체시킨다. 보통 파괴자 작동시 자동 호출된다.

void invTMul() {
	float data[] = { 1,0,2, -3,4,6, -1,-2,3 };
	cv::Mat m1(3,3, CV_32F, data);
	cv::Mat m2(cv::Matx13f(6, 30, 8)); // shape(3,1), data(6,30,8)의 행렬, y값이 된다.
	cv::Mat m2_t = m2.t(); // 

	cv::Mat m1_inv = m1.inv(cv::DECOMP_LU); //역행렬 계산
	cv::Mat x = m1_inv * m2_t; //행렬 곱
	
	std::cout << "[m1] = " << std::endl << m1 << std::endl;
	std::cout << "[m1_int] = " << std::endl << m1_inv << std::endl;
	std::cout << "[x] = " << std::endl << x << std::endl;

	std::cout << "연립방정식의 해 x1, x2, x3 = " << x.t() << std::endl << std::endl;
}