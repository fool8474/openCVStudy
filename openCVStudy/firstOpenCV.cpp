#include "mainHeader.h"
#include "firstOpenCV.h"

void first()
{
	cv::Mat image(300, 400, CV_8UC1, cv::Scalar(200));
	cv::imshow("���󺸱�", image);
	cv::waitKey(0);
}