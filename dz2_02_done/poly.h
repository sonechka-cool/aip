#pragma once
#include <iostream>
#include <vector>
using namespace std;

class polynomial {
private:
	vector<double> A;//������ ��� �������� ������������
	vector<int> E;//������ ��� �������� ��������

public:
	polynomial(int maxE, double* A);//����������� �� ����������
	polynomial(int maxE);//����������� �� ������ ����������(�� ���������)
	polynomial(const polynomial& p);//����������� �����������
	~polynomial();//�������������

	double getmax_E() const { return E.size(); };//���������� ������������ �������� �
	double get_A(int index) const;//���������� �������� �� �������
	void set_A(int index, double newA);//������������� ����� �������� � �� �������
	void reset(int maxE, double* A);//c����
	void print();//�����
	double calculate(double x);//����
};

polynomial operator+ (const polynomial & p1, const polynomial & p2);//�������� �������� ���� �������� ������ polynomial
polynomial operator- (const polynomial & p1, const polynomial & p2);//�������� ��������� ���� �������� ���� polynomial


class VectPolynomial {
private:
	vector<polynomial> polynoms;//��� ������ ������� ���� polynomial

public:
	VectPolynomial(polynomial& p);//����������� 
	VectPolynomial(const VectPolynomial& vp);//����������� �����������
	~VectPolynomial();//�������������

	int Get_amount_of_polynomials() { return polynoms.size(); };//���������� ���������� ���������

	polynomial& Polynomial_ind(int index);//���������� �� �������
	void Add_polynomial(polynomial& p) { polynoms.push_back(p); };//��������������
	void Remove_polynomial_ind(int index);//������� �� �������

	void Print();
};