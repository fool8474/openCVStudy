// OpenCV������ �簢��, ����, �� ���� �׸��� �Լ��� ����
// void line(Mat & img, Point pt1, Point pt2, const Scalar& color, int thickness = 1, int lineType = 8, int shift = 0)
// void rectangle(Mat & img, Point pt1, Point pt2, const Scalar& color, int thickness = 1, int lineType = 8, int shift = 0)
// void rectangle(Mat & img, Rect rec, const Scalar& color, int thickness = 1, int lineType = 8, int shift = 0)
// lineType���� LINE_4 = 4���� ���ἱ, LINE_8 = 8���� ���ἱ, LINE_AA = ������� ���� ��
// shift�� �Է� ��ǥ�� ���� ���������� ��Ʈ����Ʈ ������ ����� ��ǥ�� �����ؼ� ������ �׸��� �ȴ�.

#include "mainHeader.h"
#include "drawLineRect.h"
using namespace std;

void drawLineRect() {
	cv::Scalar blue(255, 0, 0), red(0, 0, 255), green(0, 255, 0);
	cv::Scalar white = cv::Scalar(255, 255, 255);
	cv::Scalar yellow(0, 255, 255);
	//Scalar���� �̸� �����ؼ� ����Ʈ���� ��������.

	cv::Mat image(400, 600, CV_8UC3, white);
	cv::Point pt1(50, 130), pt2(200, 300), pt3(300, 150), pt4(400, 50);
	cv::Rect rect(pt3, cv::Size(200, 150));

	cv::line(image, pt1, pt2, red); //50, 130, 200, 300, ������ ��
	cv::line(image, pt3, pt4, green, 2, cv::LINE_AA); //300, 150, 400, 50, ��� ��, ��Ƽ���ϸ���
	cv::line(image, pt3, pt4, green, 3, cv::LINE_8, 1); // 300, 150, 400, 50, 1����Ʈ, ��� ��, 8����

	cv::rectangle(image, rect, blue, 2); // 300, 150, 500, 300 ����2
	cv::rectangle(image, rect, blue, cv::FILLED, cv::LINE_4, 1); // 300, 150, 500, 300, 1����Ʈ, ����1, ä����, 4����
	cv::rectangle(image, pt1, pt2, red, 3); // 50, 130, 200, 300, ������, ����3

	cv::imshow("���� & �簢��", image);
	cv::waitKey(0);
}

//Font �׸���, putText()
//img, text, org, fontFace, fontScale, color, thickness=1, lineType=8, bottomLeftOrigin=false
//bottomLeftOrigin : ������ ���� ��ǥ�� �ϴ� �������� ���� (�⺻ : ��� ����)


void drawFont() {
	cv::Scalar olive(128, 128, 0), violet(221, 160, 221), brown(42, 42, 165);
	cv::Point pt1(20, 100), pt2(20, 200), pt3(30, 250);
	cv::Mat image(300, 500, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::putText(image, "SIMPLEX", cv::Point(20, 30), cv::FONT_HERSHEY_SIMPLEX, 1, brown); // ũ�� 1, SIMPLEX �۾�ü, 20,30 ����
	cv::putText(image, "DUPLEX", pt1, cv::FONT_HERSHEY_DUPLEX, 2, olive);
	cv::putText(image, "TRIPLEX", pt2, cv::FONT_HERSHEY_TRIPLEX, 3, violet);
	cv::putText(image, "ITALIC", pt3, cv::FONT_HERSHEY_PLAIN | cv::FONT_ITALIC, 2, violet); // ũ�� 2, PLAIN �۾�ü, ����
	cv::putText(image, "�ѱ��׽�Ʈ", cv::Point(100, 100), cv::FONT_HERSHEY_DUPLEX, 2, olive); // �ѱ� �۵����� ����

	cv::imshow("���ھ���", image);
	cv::waitKey(0);
}

//�� �׸��� circle()
//center�� ��ġ��, radius�� ��ü ���̸� ��´�.
//�������� rect�� ����

void drawCircle() {
	cv::Scalar orange(0, 165, 255), blue(255, 0, 0), magenta(255, 0, 255);
	cv::Mat image(300, 500, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::Point center = (cv::Point)image.size() / 2;
	cv::Point pt1(70, 50), pt2(350, 220);

	cv::circle(image, center, 100, blue);
	cv::circle(image, pt1, 80, orange, 4); //���� 4
	cv::circle(image, pt2, 60, magenta, -1); //�� ���� ä�� -�� ��� ���̴� ���µ�

	int font = cv::FONT_HERSHEY_SCRIPT_COMPLEX;
	cv::putText(image, "center_blue", center, font, 1.2, blue);
	cv::putText(image, "pt1_orange", pt1, font, 0.8, orange);
	cv::putText(image, "pt2_magenta", pt2 + cv::Point(2, 2), font, 0.5, cv::Scalar(0, 0, 0), 2); // �׸��� ȿ�� (������ ǥ��)
	cv::putText(image, "pt2_magenta", pt2, font, 0.5, magenta, 1);

	cv::imshow("���׸���", image);
	cv::waitKey(0);
}

//Ÿ�� �׸��� eclipse()
//center�� ���, size�� (x,y)�� ������ ��´�. ������ angle, startAngle, endAngle�� ����, ���� ���� ��� RotateRect�� �߽� ��ǥ, �簢�� ũ��, ȸ�� ���� �� ������ Ÿ���� �׸����� �ִ�.
void drawEclipse() {
	cv::Scalar orange(0, 165, 255), blue(255, 0, 0), magenta(255, 0, 255);
	cv::Mat image(300, 700, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::Point pt1(120, 150), pt2(550, 150);
	cv::circle(image, pt1, 1, cv::Scalar(0), 1);
	cv::circle(image, pt2, 1, cv::Scalar(0), 1); // Ÿ���� �߽��� ǥ��
	cv::ellipse(image, pt1, cv::Size(100, 60), 0, 0, 360, orange, 2); //Ÿ�� �׸��� ���� 0+
	cv::ellipse(image, pt1, cv::Size(100, 60), 0, 30, 270, blue, 4); //ȣ �׸��� 30~270
	cv::ellipse(image, pt2, cv::Size(100, 60), 30, 0, 360, orange, 2); //Ÿ�� �׸��� ���� 30
	cv::ellipse(image, pt2, cv::Size(100, 60), 30, -30, 160, magenta, 4); //ȣ �׸��� ���� 30, -30~160

	cv::imshow("Ÿ�� �� ȣ �׸���", image);
	cv::waitKey(0);
}
