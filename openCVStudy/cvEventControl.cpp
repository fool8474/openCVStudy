// 이벤트를 처리해보자.
// 콜백 함수 : 일반적으로 이벤트를 처리하기 위한 함수.
// 키보드 처리에 OpenCV는 waitkey()를 제공. :: 키 이벤트에 해당하는 정수형의 값을 반환

#include "mainHeader.h"
#include "cvEventControl.h"

using namespace std;

void keyEventTester() {
	cv::Mat image(200, 300, CV_8U, cv::Scalar(255));
	cv::namedWindow("키보드 이벤트", CV_WINDOW_AUTOSIZE);
	cv::imshow("키보드 이벤트", image);

	while (1) {
		//int key = cv::waitKey(100); //100ms동안 키이벤트 대기
		//본래 waitKey를 사용하면 되나, 화살표가 작동이 안되더라.
		//따라서 waitKeyEx()를 사용해보자. 잘 된다!

		int key = cv::waitKeyEx(100);
		if (key == 27) break; //ESC
		
		switch (key) {
		case 'a': cout << "a키 입력" << endl; break;
		case 'b': cout << "b키 입력" << endl; break;
		case 0x41: cout << "A키 입력" << endl; break;
		case 66: cout << "B키 입력" << endl; break;
		case 0x250000: cout << "왼쪽 화살표 키 입력" << endl; break;
		case 0x260000: cout << "위쪽 화살표 키 입력" << endl; break;
		case 0x270000: cout << "오른쪽 화살표 키 입력" << endl; break;
		case 0x280000: cout << "아래쪽 화살표 키 입력" << endl; break;
		}
	}
}