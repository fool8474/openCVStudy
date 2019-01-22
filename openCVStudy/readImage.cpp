// 이미지 파일 처리
// imread()는 filename, flags를 매개변수로 가짐. flag는 컬러타입을 의미한다.
// IMREAD_UNCHANGED = -1 , 파일의 지정된 컬러영상을 반환 (alpha 포함)
// IMREAD_GRAYSCALE = 0  , grayscale 영상으로 변환
// IMREAD_COLOR     = 1  , color 영상으로 변환
// IMREAD_ANYDEPTH  = 2  , 입력 파일에 정의된 깊이에 따라 16/32비트 영상으로 변환. 설정 X라면 8비트로.
// IMREAD_ANYCOLOR  = 4  , 파일에 정의된 타입으로 반환
// imwrite()는 img행렬을 영상으로 저장한다. filename, img, params가 있다. img는 해당 Mat, params는 압축 양식에 사용되는 인수 쌍들의 벡터.

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
	cout << ": depth(" << img.depth() << ") channels(" << img.channels() << ") -> 자료형 : ";
	cout << mat_type << "C" << img.channels() << endl;
}

void imgReader() {
	string filename = "../image/read_gray.jpg";
	cv::Mat gray2gray = cv::imread(filename, cv::IMREAD_GRAYSCALE); // 8UC1 grayscale로 불러옴
	cv::Mat gray2color = cv::imread(filename, cv::IMREAD_COLOR); // 8UC3 color로 불러옴
	CV_Assert(gray2gray.data && gray2color.data); // 파일이 정상적으로 로드되지 않으면 오류

	cv::Rect roi(100, 100, 1, 1);
	cout << "행렬 좌표 (100,100) 화소값 " << endl; // 97, (97,97,97)
	cout << "gray2gray " << gray2gray(roi) << endl;
	cout << "gray2color " << gray2color(roi) << endl << endl; // 사이즈가 1인 rect를 불러옴으로써 1픽셀 출력

	print_MatInfo("gray2gray", gray2gray);
	print_MatInfo("gray2color", gray2color);
	cv::imshow("gray2gray", gray2gray);
	cv::imshow("gray2color", gray2color);
	cv::waitKey(0);
}

// 이번엔 color 영상도 다뤄보자

void imgReaderColor() {
	string filename = "../image/read_color.jpg";
	cv::Mat color2gray = cv::imread(filename, cv::IMREAD_GRAYSCALE);
	cv::Mat color2color = cv::imread(filename, cv::IMREAD_COLOR);
	CV_Assert(color2gray.data && color2color.data);
	
	cv::Rect roi(100, 100, 1, 1);
	cout << "행렬 좌표 (100,100) 화소값 " << endl; // 27, (78, 31, 0)
	cout << "color2gray " << color2gray(roi) << endl; 
	cout << "color2color " << color2color(roi) << endl << endl; // 사이즈가 1인 rect를 불러옴으로써 1픽셀 출력

	print_MatInfo("color2gray", color2gray);
	print_MatInfo("color2color", color2color);
	cv::imshow("color2gray", color2gray);
	cv::imshow("color2color", color2color);
	cv::waitKey(0);
}


// tif영상은 16비트 이상이 가능. 16비트 이상의 영상을 받아보자

void tifImageReader() {
	string filename1 = "../image/read_32.tif";
	cv::Mat color2unchanged1 = cv::imread(filename1, cv::IMREAD_UNCHANGED);
	CV_Assert(color2unchanged1.data);

	cv::Rect roi(100, 100, 1, 1);
	cout << "16비트 이상 영상 행렬 좌표 (100,100) 화소값 " << endl;
	cout << "color2unchanged1 " << color2unchanged1(roi) << endl << endl; // 사이즈가 1인 rect를 불러옴으로써 1픽셀 출력

	print_MatInfo("color2unchanged1", color2unchanged1);
	cv::imshow("color2unchanged1", color2unchanged1);
	cv::waitKey(0);
}

