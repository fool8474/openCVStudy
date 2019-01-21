#include "mainHeader.h"
#include "eventToDrawRectCircle.h"

using namespace std;

string title = "이벤트 그리기";
cv::Mat image;

void onMouseDrawing(int event, int x, int y, int flags, void * param) {
	static cv::Point pt(-1, -1);
	if (event == cv::EVENT_LBUTTONDOWN) {
		if (pt.x < 0) pt = cv::Point(x, y);
		else {
			cv::rectangle(image, pt, cv::Point(x, y), cv::Scalar(50), 2);
			cv::imshow(title, image);
			pt = cv::Point(-1, -1);
		}
	}

	else if (event == cv::EVENT_RBUTTONDOWN) {
		if (pt.x < 0) pt = cv::Point(x, y);
		else {
			cv::Point2d pt2 = pt - cv::Point(x, y);
			int radius = (int)sqrt(pt2.x * pt2.x + pt2.y * pt2.y);
			cv::circle(image, pt, radius, cv::Scalar(150), 2);

			cv::imshow(title, image);
			pt = cv::Point(-1, -1);
		}
	}
}

void titleToDrawRectCircle(){
	image = cv::Mat(300, 500, CV_8UC1, cv::Scalar(255));
	cv::imshow(title, image);
	cv::setMouseCallback(title, onMouseDrawing, 0);

	cv::waitKey(0);
}