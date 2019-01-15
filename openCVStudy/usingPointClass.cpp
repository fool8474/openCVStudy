#include "mainHeader.h"
#include "usingPointClass.h"

int usingPointClass()
{
	// ��ü ���� ���
	cv::Point_<int> pt1(100, 200);
	cv::Point_<float> pt2(92.3f, 123.23f);
	cv::Point_<double> pt3(100.2, 300.9);

	// ���� ���� ���
	cv::Point2i pt4(120, 69); // int
	cv::Point2f pt5(0.3f, 0.f), pt6(0.f, 0.4f); // float
	cv::Point2d pt7(0.25, 0.6); // double

	cv::Point pt8 = pt1 + (cv::Point) pt2;
	cv::Point pt9 = pt6 * 3.14f;
	cv::Point pt10 = (pt3 + (cv::Point2d) pt6) * 10;

	std::cout << "pt8 = " << pt8.x << " , " << pt8.y << std::endl;
	std::cout << "[pt9] = " << pt9 << std::endl;
	std::cout << "pt7�� pt8�� ���� : " << pt7.dot(pt8) << std::endl;
	std::cout << "pt7�� pt8�� ���� : " << pt7.cross(pt8) << std::endl;


	// 3���� ����

	cv::Point3_<int> pt3Di(100, 200, 300);
	cv::Point3_<float> pt3Df(92.3f, 125.23f, 250.f);

	cv::Point3i pt3DiSim = pt3Di - (cv::Point3i)pt3Df;

	std::cout << pt3DiSim << std::endl;
	

	// Size�� ���������� ����� �� �ִ�. width, height�� ������. ���� ���ڸ�..
	cv::Size2f sz2f(1.3f, 0.f);
	cv::Size2i sz2i(1, 3);
	std::cout << (cv::Size2i)sz2f + sz2i << std::endl; // [2 x 3]���� ǥ�õ�
	std::cout << sz2i.area() << std::endl; // ���� ǥ�� = 3�� ����.
	
	// �簢���� �ִ�. Rect_Ŭ������ Width, Height, x, y�� �����Ѵ�. tl() = ���� ��ǥ ��ȯ, br() = ���� ��ǥ ��ȯ, size, area �Լ� ���� �ִ�.
	cv::Rect_<int> rect1(10, 10, 30, 50);
	cv::Rect2f rect2 = rect1 + (cv::Point)pt1;
	std::cout << rect2 << std::endl;
	
	// Vec�� �ִ�. ���� ������ ���� ���� ���͸� ���� �ִ�. Template���� <�ڷ���, ����>�� �����Ѵ�. ���� �������ϱ� Vec6d << (double, 6)�� ���̵� ����.
	cv::Vec6f v1(40.f, 230.25f, 525.6f); // �� ä������ 0����
	cv::Vec4i v2(1, 2, 3, 4);
	cv::Vec4d v3(1.0, 2.0);
	std::cout << (cv::Vec4i)v3 + v2 << std::endl; // �ٸ� ������ ���� ����ȯ�� �ȵǴ� ��.

	// Scalar�� 4���� ȭ�Ҹ� �����ϱ� ���� Vec<Tp, 4>���� �Ļ��Ǿ���. R,G,B,A�� ���� ������.
	cv::Scalar_<double> color1(500); // �翬�� �� ä�� �� 0����
	
	// RotatedRect�� ȸ���� �簢���̴�. point, size, angle(float)�� ������.
	cv::Mat image(300, 500, CV_8UC1, cv::Scalar(220));
	cv::Point2f center(250, 150), pts[4];
	cv::Size2f size(300, 100);
	cv::RotatedRect rot_rect(center, size, 20); //ȸ�� �簢��

	cv::Rect bound_rect = rot_rect.boundingRect();
	cv::rectangle(image, bound_rect, cv::Scalar(0), 1); //�簢�� �׸�
	cv::circle(image, rot_rect.center, 1, cv::Scalar(0), 2); //�� �׸�
	rot_rect.points(pts);
	for (int i = 0; i < 4; i++) {
		circle(image, pts[i], 4, cv::Scalar(0), 1);
		line(image, pts[i], pts[(i + 1) % 4], cv::Scalar(0), 2);
	}

	cv::imshow("ȸ���簢��", image);
	cv::waitKey(0);
	return 0;
}