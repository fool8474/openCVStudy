//이번엔 이미지를 저장해보자.
//imwrite()
//IMWRITE_JPEG_QUALITY = JPG파일 화질, 높은 값일수록 좋은 화질
//IMWRITE_PNG_COMPRESSION = PNG파일 화질, 높은 값일수록 적은 용량, 긴 압축시간
//IMWRITE_PXM_BINARY = PPM, PGM 파일의 이진 포맷 설정

#include "mainHeader.h"

using namespace std;

void writeImage() {
	cv::Mat img8 = cv::imread("../image/read_color.jpg", cv::IMREAD_COLOR);
	CV_Assert(img8.data);

	// Vector Option의 설정
	vector<int> params_jpg, params_png;
	params_jpg.push_back(cv::IMWRITE_JPEG_QUALITY); // JPG화질설정
	params_jpg.push_back(50);
	params_png.push_back(cv::IMWRITE_PNG_COMPRESSION); // PNG압축레벨로ㄴ
	params_png.push_back(9);

	cv::imwrite("../image/write_test1.jpg", img8); // 행렬 영상파일로
	cv::imwrite("../image/write_test2.jpg", img8, params_jpg); // 지정파일로
	cv::imwrite("../image/write_test.png", img8, params_png); // PNG파일로
	cv::imwrite("../image/write_test.bmp", img8); // BMP파일로
}

void writeImageTo16And32() {
	cv::Mat img8 = cv::imread("../image/read_8.tif", cv::IMREAD_COLOR); //8bit tif파일
	CV_Assert(img8.data); 
	cv::Mat img16, img32;
	img8.convertTo(img16, CV_16U, 65535 / 255.0); // 65535/255.0은 uchar형 화소값을 ushort형에 맞게 변형
	img8.convertTo(img32, CV_32F, 1 / 255.0f);  // 1/255.0f는 float형에 맞게 0~1 사이 값으로 변형

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



