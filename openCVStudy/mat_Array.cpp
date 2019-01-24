#include "mainHeader.h"

using namespace std;
using namespace cv;

void mat_Array(){
	Mat image = imread("../image/kawaii.jpg");
	CV_Assert(image.data);

	Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
	flip(image, x_axis, 0); // x축 상하 뒤집기
	flip(image, y_axis, 1); // y축 좌우 뒤집기
	flip(image, xy_axis, -1); // 대각 뒤집기

	repeat(image, 1, 2, rep_img); // 반복 복사 (세로방향 1회, 가로방향 2회)
	transpose(image, trans_img); // 행렬 전치 

	imshow("image", image), imshow("x_axis", x_axis);
	imshow("y_axis", y_axis), imshow("xy_axis", xy_axis);
	imshow("rep_img", rep_img), imshow("trans_img", trans_img);
	waitKey();
}

