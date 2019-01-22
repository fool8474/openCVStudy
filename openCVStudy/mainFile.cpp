#include "mainHeader.h"

int main(void) {
	/* Chap 2 */
	//usingPointClass(); //Point 연습.
	//MatTutorial(); //Mat, Mat_, Matx 기초
	//MatInitialize(); //Mat 초기화
	//MatAdjust(); //Mat size, shape 조절
	//vectorInfo(); // Vector
	//rangeTest(); // Range
	//ROIMethod(); // Range 바꾸기, 조절
	//invTMul(); // inv, T, mul을 이용한 방정식 풀이

	/* Chap 3 */
	//helloWindow(); //윈도우 띄우기, Mat 반영하기, 사이즈 조절, 위치 조정
	//keyEventTester(); //key 입력에 따른 반응 (waitKeyEx와 while을 이용)
	//mouseEventTester(); //마우스도 함께 입력할때 반응
	//barTest(); //bar를 조절하여 밝기 변화
	//barMouseTest(); //마우스 클릭을 통해서 밝기 변화
	//drawLineRect(); // 선과 사각형 그리기
	//drawFont(); // 폰트 그리기
	//drawCircle(); // 원+폰트 그리기
	//drawEclipse(); //타원 그리기
	//titleToDrawRectCircle(); // 전체 그리기 테스트

	//imgReader(); // grayscale 파일 불러오기
	//imgReaderColor(); // color 파일 불러오기
	//tifImageReader(); // 16/32비트의 tif파일 불러오기
	//writeImage(); // jpg color 파일을 불러와 jpg, bmp, png로 저장
	//writeImageTo16And32(); // 8UC3 파일을 16UC3, 32FC3으로 변환 저장
	//helloVideo(); // video 정보를 출력, font 삽입
	setCamera(); // trackbar를 통해 영상의 zoom과 focus를 조절
	system("pause");

	return 0;
}