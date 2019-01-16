#include "mainHeader.h"

int vectorInfo() {
	/*
	Vector는 배열 크기가 자동 조정, C언어 배열 급의 빠른 접근, 원소 추가 / 삭제가 용이하다
	*/

	std::vector<cv::Point> v1;
	v1.push_back(cv::Point(10, 20));
	v1.push_back(cv::Point(10, 30));
	v1.push_back(cv::Point(10, 40)); //벡터에 원소 추가

	std::vector<float> v2(3, 9.25); //벡터 선언 및 초기화
	
	int arr_int[] = { 10,20,30,40,50 };
	std::vector<int> v4(arr_int + 2, arr_int + sizeof(arr_int) / sizeof(int)); // int형 배열원소 벡터 선언
	//배열 시작주소 + 2를 지정, 그리고 마지막 원소까지 삽입

	std::cout << "[v4]" << ((cv::Mat)v4).reshape(1, 1) << std::endl; //reshape()후 1행 출력

	std::vector<int> v5(arr_int, arr_int + sizeof(arr_int) / sizeof(int));
	v5.insert(v5.begin() + 2, 100); //3번째에 원소 100 추가
	print_vectorInfo("v5, insert(2)", v5);

	v5.erase(v5.begin() + 3); //4번째 원소 제거
	print_vectorInfo("v5, erase(3)", v5);
	
	v5.clear(); //원소 전체 삭제
	print_vectorInfo("v5, clear()", v5);
	
	//vector의 재할당으로 속도 저하를 줄이자! 무려 3배정도나 줄일 수 있다.
	v5.reserve(10000000);
}

void print_vectorInfo(std::string v_name, std::vector<int> v) {
	std::cout << "[" << v_name << " ] = ";
	if (v.empty()) std::cout << "벡터가 비어있습니다. " << std::endl;
	else std::cout << ((cv::Mat)v).reshape(1, 1) << std::endl;

	std::cout << ".size() = " << v.size() << std::endl;
}

