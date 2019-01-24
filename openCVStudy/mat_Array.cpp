#include "mainHeader.h"

using namespace std;
using namespace cv;

void mat_Array(){
	Mat image = imread("../image/kawaii.jpg");
	CV_Assert(image.data);

	Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
	flip(image, x_axis, 0); // x�� ���� ������
	flip(image, y_axis, 1); // y�� �¿� ������
	flip(image, xy_axis, -1); // �밢 ������

	repeat(image, 1, 2, rep_img); // �ݺ� ���� (���ι��� 1ȸ, ���ι��� 2ȸ)
	transpose(image, trans_img); // ��� ��ġ 

	imshow("image", image), imshow("x_axis", x_axis);
	imshow("y_axis", y_axis), imshow("xy_axis", xy_axis);
	imshow("rep_img", rep_img), imshow("trans_img", trans_img);
	waitKey();
}

