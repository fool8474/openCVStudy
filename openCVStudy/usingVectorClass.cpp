#include "mainHeader.h"

int vectorInfo() {
	/*
	Vector�� �迭 ũ�Ⱑ �ڵ� ����, C��� �迭 ���� ���� ����, ���� �߰� / ������ �����ϴ�
	*/

	std::vector<cv::Point> v1;
	v1.push_back(cv::Point(10, 20));
	v1.push_back(cv::Point(10, 30));
	v1.push_back(cv::Point(10, 40)); //���Ϳ� ���� �߰�

	std::vector<float> v2(3, 9.25); //���� ���� �� �ʱ�ȭ
	
	int arr_int[] = { 10,20,30,40,50 };
	std::vector<int> v4(arr_int + 2, arr_int + sizeof(arr_int) / sizeof(int)); // int�� �迭���� ���� ����
	//�迭 �����ּ� + 2�� ����, �׸��� ������ ���ұ��� ����

	std::cout << "[v4]" << ((cv::Mat)v4).reshape(1, 1) << std::endl; //reshape()�� 1�� ���

	std::vector<int> v5(arr_int, arr_int + sizeof(arr_int) / sizeof(int));
	v5.insert(v5.begin() + 2, 100); //3��°�� ���� 100 �߰�
	print_vectorInfo("v5, insert(2)", v5);

	v5.erase(v5.begin() + 3); //4��° ���� ����
	print_vectorInfo("v5, erase(3)", v5);
	
	v5.clear(); //���� ��ü ����
	print_vectorInfo("v5, clear()", v5);
	
	//vector�� ���Ҵ����� �ӵ� ���ϸ� ������! ���� 3�������� ���� �� �ִ�.
	v5.reserve(10000000);
}

void print_vectorInfo(std::string v_name, std::vector<int> v) {
	std::cout << "[" << v_name << " ] = ";
	if (v.empty()) std::cout << "���Ͱ� ����ֽ��ϴ�. " << std::endl;
	else std::cout << ((cv::Mat)v).reshape(1, 1) << std::endl;

	std::cout << ".size() = " << v.size() << std::endl;
}

