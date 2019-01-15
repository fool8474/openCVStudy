#include "mainHeader.h"
#include "usingMatClass.h"

// OpenCV 1.x�� IpImage�� ���. �̴� C����� ������ �״�� ������ ����.
// OpenCV 2.x���ʹ� C++ �������̽��� ����. Mat�� ���� ������ ǥ��.

/*
Mat�� ������ �� �ִ� ���
���� ä�� & ���� ä�� ��
�Ǽ� & ���Ҽ��� ������ ����
GrayScale�����̳� Color���� ������
���� ����
������׷� ������
*/

// ��� �ڷ����� �ſ� �����ؾ���!
/*
CV_8U : uchar
CV_16S : signed short int
CV_32F : float
*/

//Mat, Mat_, Matx�� �ִ�!

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
	Mat m1 = Mat::ones(3, 5, CV_8UC1); //1�� �ʱ�ȭ
	Mat m2 = Mat::zeros(3, 5, CV_8UC1); //0���� �ʱ�ȭ
	Mat m3 = Mat::eye(8, 8, CV_8UC1); // ������ ũ��� Ÿ���� ���� ���
	/*
	m3 :
		loop (x,y) :
			if x == y : point(x,y) = 1
			else : point(x,y) = 0
	*/

	cout << "[m1] =" << endl << m1 << endl;
	cout << "[m2] =" << endl << m2 << endl;
	cout << "[m3] =" << endl << m3 << endl;

	//�̹��� Mat_Ŭ������ �̿��ؼ� �ʱ�ȭ�غ���.
	//Mat_Ŭ���� ���� <<�����ڸ� �̿��� ���� ���Ҹ� �ѹ��� �ʱ�ȭ�� �����ϴ�.

	double a = 32.12345678, b = 2.7;
	short c = 400;
	float d = 10.f, e = 11.f, f = 13.f;

	Mat_<int> m_1(2, 4);
	Mat_<uchar> m_2(3, 4, 100);
	Mat_<short> m_3(4, 5, c);

	m_1 << 1, 2, 3, 4, 5, 6; // <<�� ���� �ѹ��� ����
	Mat m_4 = (Mat_<double>(2, 3) << 1, 2, 3, 4, 5, 6);
	Mat m_5 = (Mat_<float>(2, 3) << a, b, c, d, e, f); // <<�� ���� float 2,3 ��Ŀ� a,b,c,d,e,f ����


	//�̹��� Matx Ŭ������ �̿��ؼ� �ʱ�ȭ�غ���.
	//MatxŬ������ �̿�� ���� ������ �����ϴ�.

	Matx23d mx4(3, 4, 5, 6, 7, 8);
	Matx34d mx5(1, 2, 3, 10, 11, 12, 13, 14, 15);
	Matx66f mx6(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	cout << "m5(0,0) = " << mx5(0, 0) << " m5(1,0) = " << mx5(1, 0) << endl;

	return 0;
}

//���� �� �޼ҵ尡 �ִ�
void MatInfor() {
	/*
		Mat :: dims ���� ��
		Mat :: rows �� ��
		Mat :: cols �� ��
		Mat :: data �� ����Ʈ ������
		Mat :: step �� �� ����Ʈ ��
	*/

	/*
		Mat :: channels() ä�� �� (CV_8UC1���� C1)
		Mat :: depth() ����(����� �ڷ���) (CV_8UC1���� CV_8U)
		Mat :: elemSize() ��� ���� ����Ʈ ũ��
		Mat :: elemSize1() ��� �� ä�� ����Ʈ ũ��
		Mat :: empty() ����ִ���
		Mat :: isSubmatrix() ���� ������� ����
		Mat :: size() ũ�� size������ ��ȯ
		Mat :: step1() elemSize1�� ������ ����ȭ�� step ��ȯ
		Mat :: total() ���� ��ü ���� ��ȯ
		Mat :: type() ������ Ÿ��(�ڷ��� + ä�� ��) ��ȯ, �ڷ��� 3��Ʈ, ä�� �� 3��Ʈ��..
	*/

	/*
		Quiz
		���� 4,3,CV_32FC3�� Mat�� �ִٸ�?
		dims : 2
		rows : 4
		cols : 3
		data : �����Ͱ� ������ ������ ������ ����
		step : 36 (12x3)
		channels : 3
		depth : 5
		elemSize : 12
		elemSize1 : 4
		empty : ������ False, ������ True
		isSubmatrix : �����ϸ� True, �ƴϸ� False
		size : [3 x 4]
		step1 : 9
		total : 12
		type : 21
	*/

	// Mat������ �پ��� ���굵 �����ϴ�!
	// m1 = 100 : ��� ���Ҹ� �ش� ��Į������
	// m1 = m2 + m3
	// m1 = m2 (m2����� �ּҸ� m1�� �����Ѵ�)
}

int MatAdjust() {

	//resize�� reshape �Լ��� ���� mat�� �缳������.

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

	//Mat�� Copy�غ���
	m1 = (Mat_<uchar>(3, 5) << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	Mat m3, m4, m5;
	m1.copyTo(m3); // �����͸� ����
	m5 = m1.clone(); // ���� ���� ������ ��ȯ

	cout << m1 << endl;
	cout << m3 << endl;
	cout << m4 << endl;
	cout << m5 << endl;

	return 0;

}











