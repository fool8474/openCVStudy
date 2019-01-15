#include "mainHeader.h"
#include "usingPointClass.h"

int usingPointClass()
{
	// 객체 선언 방식
	cv::Point_<int> pt1(100, 200);
	cv::Point_<float> pt2(92.3f, 123.23f);
	cv::Point_<double> pt3(100.2, 300.9);

	// 간결 선언 방식
	cv::Point2i pt4(120, 69); // int
	cv::Point2f pt5(0.3f, 0.f), pt6(0.f, 0.4f); // float
	cv::Point2d pt7(0.25, 0.6); // double

	cv::Point pt8 = pt1 + (cv::Point) pt2;
	cv::Point pt9 = pt6 * 3.14f;
	cv::Point pt10 = (pt3 + (cv::Point2d) pt6) * 10;

	std::cout << "pt8 = " << pt8.x << " , " << pt8.y << std::endl;
	std::cout << "[pt9] = " << pt9 << std::endl;
	std::cout << "pt7과 pt8의 내적 : " << pt7.dot(pt8) << std::endl;
	std::cout << "pt7과 pt8의 외적 : " << pt7.cross(pt8) << std::endl;


	// 3차원 선언

	cv::Point3_<int> pt3Di(100, 200, 300);
	cv::Point3_<float> pt3Df(92.3f, 125.23f, 250.f);

	cv::Point3i pt3DiSim = pt3Di - (cv::Point3i)pt3Df;

	std::cout << pt3DiSim << std::endl;
	

	// Size도 마찬가지로 사용할 수 있다. width, height를 가진다. 맛만 보자면..
	cv::Size2f sz2f(1.3f, 0.f);
	cv::Size2i sz2i(1, 3);
	std::cout << (cv::Size2i)sz2f + sz2i << std::endl; // [2 x 3]으로 표시됨
	std::cout << sz2i.area() << std::endl; // 넓이 표현 = 3이 나옴.
	
	// 사각형도 있다. Rect_클래스는 Width, Height, x, y를 포함한다. tl() = 시작 좌표 반환, br() = 종료 좌표 반환, size, area 함수 등이 있다.
	cv::Rect_<int> rect1(10, 10, 30, 50);
	cv::Rect2f rect2 = rect1 + (cv::Point)pt1;
	std::cout << rect2 << std::endl;
	
	// Vec도 있다. 원소 개수가 작은 숫자 벡터를 위해 있다. Template으로 <자료형, 개수>로 선언한다. 물론 귀찮으니까 Vec6d << (double, 6)과 같이도 만듬.
	cv::Vec6f v1(40.f, 230.25f, 525.6f); // 안 채워진건 0으로
	cv::Vec4i v2(1, 2, 3, 4);
	cv::Vec4d v3(1.0, 2.0);
	std::cout << (cv::Vec4i)v3 + v2 << std::endl; // 다른 차원인 것은 형변환이 안되는 듯.

	// Scalar는 4개의 화소를 지정하기 위해 Vec<Tp, 4>에서 파생되었다. R,G,B,A의 값을 가진다.
	cv::Scalar_<double> color1(500); // 당연히 안 채운 건 0으로
	
	// RotatedRect는 회전된 사각형이다. point, size, angle(float)를 가진다.
	cv::Mat image(300, 500, CV_8UC1, cv::Scalar(220));
	cv::Point2f center(250, 150), pts[4];
	cv::Size2f size(300, 100);
	cv::RotatedRect rot_rect(center, size, 20); //회전 사각형

	cv::Rect bound_rect = rot_rect.boundingRect();
	cv::rectangle(image, bound_rect, cv::Scalar(0), 1); //사각형 그림
	cv::circle(image, rot_rect.center, 1, cv::Scalar(0), 2); //원 그림
	rot_rect.points(pts);
	for (int i = 0; i < 4; i++) {
		circle(image, pts[i], 4, cv::Scalar(0), 1);
		line(image, pts[i], pts[(i + 1) % 4], cv::Scalar(0), 2);
	}

	cv::imshow("회전사각형", image);
	cv::waitKey(0);
	return 0;
}