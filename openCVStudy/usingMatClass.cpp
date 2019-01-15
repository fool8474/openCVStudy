#include "mainHeader.h"
#include "usingMatClass.h"

// OpenCV 1.x는 IpImage를 사용. 이는 C언어의 단점을 그대로 가지고 있음.
// OpenCV 2.x부터는 C++ 인터페이스를 도입. Mat로 영상 데이터 표현.

/*
Mat가 저장할 수 있는 목록
단일 채널 & 다중 채널 값
실수 & 복소수로 구성된 벡터
GrayScale영상이나 Color영상 데이터
점의 집합
히스토그램 데이터
*/

// 행렬 자료형에 매우 유의해야함!
/*
CV_8U : uchar
CV_16S : signed short int
CV_32F : float
*/

//Mat, Mat_, Matx가 있다!

using namespace cv;
using namespace std;

int MatTutorial(){
	float data[] = {
		1.2f, 2.3f, 3.2f, 4.5f, 5.f, 6.5f
	};
	Mat m1(2, 3, CV_8U); //0,0,0 0,0,0
	Mat m2(2, 3, CV_8U, Scalar(300)); //255,255,255 255,255,255
	Mat m3(2, 3, CV_16S, Scalar(300)); //300,300,300 300,300,300
	Mat m4(2, 3, CV_32F, data); //1.2,2.3,3.2 4.5,5,6.5

	Size sz(2, 3);
	Mat m5(Size(2, 3), CV_64F); // 8.4787..., 0,0 0,0,0
	Mat m6(sz, CV_32F, data); // 1.2,2.3,3.2 4.5,5,6.5

	cout << "[m1] =" << endl << m1 << endl;
	cout << "[m2] =" << endl << m2 << endl;
	cout << "[m3] =" << endl << m3 << endl;
	cout << "[m4] =" << endl << m4 << endl;
	cout << "[m5] =" << endl << m5 << endl;
	cout << "[m6] =" << endl << m6 << endl;
	return 0;
	getchar();
}

int MatInitialize() {
	Mat m1 = Mat::ones(3, 5, CV_8UC1); //1로 초기화
	Mat m2 = Mat::zeros(3, 5, CV_8UC1); //0으로 초기화
	Mat m3 = Mat::eye(8, 8, CV_8UC1); // 지정된 크기와 타입의 단위 행렬
	/*
	m3 :
		loop (x,y) :
			if x == y : point(x,y) = 1
			else : point(x,y) = 0
	*/

	cout << "[m1] =" << endl << m1 << endl;
	cout << "[m2] =" << endl << m2 << endl;
	cout << "[m3] =" << endl << m3 << endl;

	//이번엔 Mat_클래스를 이용해서 초기화해보자.
	//Mat_클래스 사용시 <<연산자를 이용해 개별 원소를 한번에 초기화가 가능하다.

	double a = 32.12345678, b = 2.7;
	short c = 400;
	float d = 10.f, e = 11.f, f = 13.f;

	Mat_<int> m_1(2, 4);
	Mat_<uchar> m_2(3, 4, 100);
	Mat_<short> m_3(4, 5, c);

	m_1 << 1, 2, 3, 4, 5, 6; // <<를 통해 한번에 지정
	Mat m_4 = (Mat_<double>(2, 3) << 1, 2, 3, 4, 5, 6);
	Mat m_5 = (Mat_<float>(2, 3) << a, b, c, d, e, f); // <<를 통해 float 2,3 행렬에 a,b,c,d,e,f 지정


	//이번엔 Matx 클래스를 이용해서 초기화해보자.
	//Matx클래스를 이용시 원소 접근이 간편하다.

	Matx23d mx4(3, 4, 5, 6, 7, 8);
	Matx34d mx5(1, 2, 3, 10, 11, 12, 13, 14, 15);
	Matx66f mx6(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	cout << "m5(0,0) = " << mx5(0, 0) << " m5(1,0) = " << mx5(1, 0) << endl;

	return 0;
}

//별의 별 메소드가 있다
void MatInfor() {
	/*
		Mat :: dims 차원 수
		Mat :: rows 행 수
		Mat :: cols 열 수
		Mat :: data 전 포인트 데이터
		Mat :: step 한 행 바이트 수
	*/

	/*
		Mat :: channels() 채널 수 (CV_8UC1에서 C1)
		Mat :: depth() 깊이(행렬의 자료형) (CV_8UC1에서 CV_8U)
		Mat :: elemSize() 행렬 원소 바이트 크기
		Mat :: elemSize1() 행렬 한 채널 바이트 크기
		Mat :: empty() 비어있는지
		Mat :: isSubmatrix() 참조 행렬인지 여부
		Mat :: size() 크기 size형으로 반환
		Mat :: step1() elemSize1로 나누어 정규화된 step 반환
		Mat :: total() 원소 전체 개수 반환
		Mat :: type() 데이터 타입(자료형 + 채널 수) 반환, 자료형 3비트, 채널 수 3비트로..
	*/

	/*
		Quiz
		만약 4,3,CV_32FC3인 Mat가 있다면?
		dims : 2
		rows : 4
		cols : 3
		data : 데이터가 있으면 나오고 없으면 없음
		step : 36 (12x3)
		channels : 3
		depth : 5
		elemSize : 12
		elemSize1 : 4
		empty : 있으면 False, 없으면 True
		isSubmatrix : 참조하면 True, 아니면 False
		size : [3 x 4]
		step1 : 9
		total : 12
		type : 21
	*/

	// Mat끼리는 다양한 연산도 가능하다!
	// m1 = 100 : 모든 원소를 해당 스칼라값으로
	// m1 = m2 + m3
	// m1 = m2 (m2행렬의 주소를 m1이 공유한다)
}

int MatAdjust() {

	//resize와 reshape 함수를 통해 mat를 재설정하자.

	Mat m1 = (Mat_<uchar>(2, 4) << 1, 2, 3, 4, 5, 6, 7, 8);
	m1.resize(5);
	cout << "m.resize(5)" << endl << m1 << endl;
	m1.resize(3);
	cout << "m.resize(3)" << endl << m1 << endl;
	m1.resize(1);
	cout << "m.resize(1)" << endl << m1 << endl;
	
	Mat m2(2, 6, CV_8U);
	cout << "m.channel : " << m2.channels() << endl;
	cout << "m.rows x m.cols : " << m2.rows << ", " << m2.cols << endl;
	m2 = m2.reshape(3, 2);
	cout << "m.channel : " << m2.channels() << endl;
	cout << "m.rows x m.cols : " << m2.rows << ", " << m2.cols << endl;

	//Mat를 Copy해보자
	m1 = (Mat_<uchar>(3, 5) << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	Mat m3, m4, m5;
	m1.copyTo(m3); // 데이터를 복사
	m5 = m1.clone(); // 같은 값을 복사해 반환

	cout << m1 << endl;
	cout << m3 << endl;
	cout << m4 << endl;
	cout << m5 << endl;

	return 0;

}











