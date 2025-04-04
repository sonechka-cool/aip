#include <iostream>
#include "poly.h"
using namespace std;
int main()
{
	srand(1);//�������������� ��������� ��������� �����
	double M1[4] = { 0, 0, 0, 0 };//������� ������ ������������
	for (int j = 0; j < 4; j++) {//��������� ������ ���������� �������
		M1[j] = rand() % 21 - 10;//����������� ������� �������� ��� ��������
	}

	polynomial P1(3, M1);//�������� ����������� ��� �������� 3�� ������� � ������������� �� ������� �
	VectPolynomial V1(P1);//��������� ������ � ��������� �1 � �������� ���������� �������
	//���� ��� �������� ����� ��������
	for (int i = 0; i < 3; i++) {
		double m[4] = { 0, 0, 0, 0 };
		for (int j = 0; j < 4; j++) {
			m[j] = rand() % 21 - 10;
		}
		//��������� ������� � ������
		polynomial ip(3, m);
		V1.Add_polynomial(ip);
	}
	//����� ��������� V1
	V1.Print();
	cout << endl;

	double M2[4] = { 0, 0, 0, 0 };
	for (int j = 0; j < 4; j++) {
		M2[j] = rand() % 21 - 10;
	}
	//�������� �������� �2 � ������� V2
	polynomial P2(3, M2);
	VectPolynomial V2(P2);
	for (int i = 0; i < 3; i++) {
		double m[4] = { 0, 0, 0, 0 };
		for (int j = 0; j < 4; j++) {
			m[j] = rand() % 21 - 10;
		}
		//��������� ������� � ������
		polynomial ip(3, m);
		V2.Add_polynomial(ip);
	}

	V2.Print();
	cout << endl;
};
//�������� � V3 � V4