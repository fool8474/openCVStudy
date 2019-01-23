// HIGHGUI 라이브러리로 동영상 처리가 가능

// VideoCapture() 생성자
// open() 열기
// isOpened()
// release() 연결 해제
// get() 지정된 속성의 값 반환
// set() 속성 설정
// grab() 다음 프레임 잡기
// retrieve() grab()으로 잡은 프레임 디코드해 image로 전달
// read(), >> 다음 프레임 디코드, image행렬로 전달. (grab, retrieve 동시 수행)

// VideoWriter() 생성자
// open() 열기
// isOpened()
// write() 저장

// 카메라 속성 식별자
// CAP_PROP_...
// POS_MSEC 현재 위치
// POS_FRAMES 캡처되는 프레임 번호
// POS_AVI_RATIO 상대적 위치 (0~1)
// FRAME_WIDTH 프레임 너비
// FRAME_HEIGHT 프레임 높이
// FPS 초당 프레임
// FOURCC 코덱 4문자
// FRAME_COUNT 총 프레임 수
// MODE Mat영상 포맷
// AUTOFOCUS 자동 초점 조절

// 코덱 문자
// CV_FOURCC_PROMPT 코덱 선택 대화창 띄움

#include "mainHeader.h"
using namespace std;

cv::VideoCapture capture;


void put_string(cv::Mat &frame, std::string text, cv::Point pt, int value) {
	text += to_string(value);
	cv::Point shade = pt + cv::Point(2, 2);
	int font = cv::FONT_HERSHEY_SIMPLEX;
	putText(frame, text, shade, font, 0.7, cv::Scalar(0, 0, 0), 2);
	putText(frame, text, pt, font, 0.7, cv::Scalar(120, 200, 90), 2);
} //그림자 효과를 가진 문자 넣기


void helloVideo() {
	capture.open("../video/sample.mp4");
	if (!capture.isOpened()) {
		cout << "카메라가 연결되지 않았습니다." << endl;
		cv::waitKey();
		exit(1);
	}

	cout << "너비 : " << capture.get(cv::CAP_PROP_FRAME_WIDTH) << endl;
	cout << "높이 : " << capture.get(cv::CAP_PROP_FRAME_HEIGHT) << endl;
	cout << "노출 : " << capture.get(cv::CAP_PROP_EXPOSURE) << endl;
	cout << "밝기 : " << capture.get(cv::CAP_PROP_BRIGHTNESS) << endl;

	for (;;) {
		cv::Mat frame;
		capture.read(frame);

		put_string(frame, "EXPOS: ", cv::Point(10, 40), capture.get(cv::CAP_PROP_EXPOSURE)); // 녹색의 EXPOS 삽입
		imshow("카메라 영상보기", frame);
		if (cv::waitKey(30) >= 0) break;
	}
}


void zoom_bar(int value, void*) {
	capture.set(cv::CAP_PROP_ZOOM, value); // zoom 설정
}

void focus_bar(int value, void*) {
	capture.set(cv::CAP_PROP_FOCUS, value); // focus 설정
}

void setCamera() {
	capture.open("../video/sampleWakako.avi"); // 사실 자체 내장 카메라 0번을 연결해서 사용해야 바뀜 (capture.open(0))
	CV_Assert(capture.isOpened());

	capture.set(cv::CAP_PROP_FRAME_WIDTH, 400); // 카메라 프레임 너비
	capture.set(cv::CAP_PROP_FRAME_HEIGHT, 300);
	capture.set(cv::CAP_PROP_AUTOFOCUS, 0); // 오토포커싱 중지
	capture.set(cv::CAP_PROP_BRIGHTNESS, 150); // 프레임 밝기 초기화

	int zoom = capture.get(cv::CAP_PROP_ZOOM); // 카메라 속성 가져오기
	int focus = capture.get(cv::CAP_PROP_FOCUS);

	string title = "카메라 속성변경"; // 윈도우 이름 지정
	cv::namedWindow(title); // 윈도우 생성
	cv::createTrackbar("zoom", title, &zoom, 10, zoom_bar); // 윈도우 줌 트랙바
	cv::createTrackbar("focus", title, &focus, 40, focus_bar); // 윈도우 포커스 트랙바
	
	for (;;) {
		cv::Mat frame; // 카메라 영상받기
		capture >> frame;

		put_string(frame, "zoom : ", cv::Point(10, 240), zoom);
		put_string(frame, "focus : ", cv::Point(10, 270), focus);

		cv::imshow(title, frame);
		if (cv::waitKey(30) >= 0) break;
	}
}

// 비디오 파일을 받아서 조정해보자.
void adjustVideoFile() {
	capture.open("../video/sampleWakako.avi");
	CV_Assert(capture.isOpened());

	double frame_rate = capture.get(CV_CAP_PROP_FPS); // 초당 프레임 수
	int delay = 1000 / frame_rate; // 지연시간
	int frame_cnt = 0;
	cv::Mat frame;

	while (capture.read(frame)) {
		if (cv::waitKey(delay) >= 0) break;

		frame_cnt = capture.get(cv::CAP_PROP_POS_FRAMES); // Frame 번호를 가져온다.

		if (frame_cnt < 100);
		else if (frame_cnt < 200) frame -= cv::Scalar(0, 0, 100);
		else if (frame_cnt < 300) frame += cv::Scalar(100, 0, 0);
		else if (frame_cnt < 400) frame = frame * 1.5;
		else if (frame_cnt < 500) frame = frame * 0.5;
		// 프레임 번호마다 다른 화소값이 된다.

		put_string(frame, "frame_cnt", cv::Point(20, 50), frame_cnt);
		cv::imshow("동영상 파일읽기", frame);
	}
}











