#include "poly.h"
using namespace std;

//����� ������������ �� ����������
polynomial::polynomial(int maxE, double* A) {
	//�������������� ���������,�������� ������� � � �
	for (int i = 0; i < maxE + 1; i++) {
		this->E.push_back(i);
		this->A.push_back(*(A + i));
	}
}

//����� ������������ �� ���������
polynomial::polynomial(int maxE) {
	//� ������ � ��������� �� 0 �� ���� �, � ������ � �������� ������
	for (int i = 0; i < maxE + 1; i++) {
		this->E.push_back(i);
		this->A.push_back(0);
	}
}

//����� ������������ �����������
polynomial::polynomial(const polynomial& p) {
	//��������� ��������
	for (int i = 0; i < p.E.size(); i++) {
		this->E.push_back(i);
		this->A.push_back(p.A.at(i));
	}
}
//�������������
polynomial::~polynomial() {
}

//��������� �������� �� �����������
double polynomial::get_A(int index) const {
	//��������� ������� 
	if (index >= getmax_E() || index < 0)
		return 0;
	return A.at(index);
}

//�������� �� ��������� �������
void polynomial::set_A(int index, double newA) {
	//�������� �����������
	if (index < 0)
		return;
	//��������� �������
	while (index >= getmax_E()) {
		E.push_back(getmax_E());
		A.push_back(0);
	}
	//������������� ����� ��������
	A.at(index) = newA;
}

//���������� ��������
void polynomial::reset(int maxE, double* A) {
	//������� ������ ������
	this->E.clear();
	this->A.clear();
	//��������� ����� ������
	for (int i = 0; i < maxE + 1; i++) {
		this->E.push_back(i);
		this->A.push_back(*(A + i));
	}
}

//����� ���������� �� �����
void polynomial::print() {
	//���������� ���������� ��������� � ������� �
	int n = E.size();
	//����������� ��������� �� ������� ����
	bool is_first_printed = false;
	//���������� �� ���� ������������ �� n
	for (int i = 0; i < n; i++) {
		double Ai = A.at(i);
		//���� ���������� ����� 0, �� ��� ������
		if (Ai == 0)
			continue;
		//���� ��� �� ������� ����, �� ������ ������ �� ������
		if (is_first_printed) {
			if (Ai > 0) {
				cout << " + ";
			}
			if (Ai < 0) {
				cout << " - ";
				Ai *= -1;
			}
		}
		//���� ���� �� ����� 1 ��� �� ������, �� �������� ���
		if (Ai != 1 || i == 0) {
			cout << Ai;
		}

		//������ ������ ���������� � ��� ���������-����� ���� ��������-true
		is_first_printed = true;
		//���� ��� �� ������� ����, �� ��������� x
		if (i != 0)
			cout << "x";
		if (i > 1)//��������� �������
			cout << "^" << E.at(i);
	}
	cout << endl;
}

//��������� �������� ��� ������� ����������
double polynomial::calculate(double x) {
	//�������������� ����� ������������
	double f = get_A(0);
	//��������� �������
	int n = getmax_E() + 1;
	//��������� �������� ����������
	for (int i = 1; i < n; i++) {
		f += get_A(i) * pow(x, i);
	}
	return f;
}

//���������� 2 ����������
polynomial operator+ (const polynomial& p1, const polynomial& p2) {
	//���������� ������������ �������
	int maxE = p1.getmax_E() >= p2.getmax_E() ? p2.getmax_E() : p1.getmax_E();
	//������� ����� ��������� � ������������ ��������
	polynomial f(maxE);

	//�������� ��������������� ����
	for (int i = 0; i < maxE + 1; i++) {
		f.set_A(i, p1.get_A(i) + p2.get_A(i));
	}
	return f;
}


//���������. ���������� ��������
polynomial operator- (const polynomial& p1, const polynomial& p2) {
	int maxE = p1.getmax_E() >= p2.getmax_E() ? p1.getmax_E() : p2.getmax_E();
	polynomial f(maxE);

	for (int i = 0; i < maxE + 1; i++) {
		f.set_A(i, p1.get_A(i) - p2.get_A(i));
	}
	return f;
}

//����������� �����������
VectPolynomial::VectPolynomial(polynomial& p) {
	polynoms.push_back(p);
}
VectPolynomial::VectPolynomial(const VectPolynomial& vp) {
	for (int i = 0; i < polynoms.size(); i++) {
		polynoms.push_back(vp.polynoms.at(i));
	}
}
//����������
VectPolynomial::~VectPolynomial() {

}

//�������� �������� �� �������
void VectPolynomial::Remove_polynomial_ind(int index) {
	if (index < 0 || index > Get_amount_of_polynomials() - 1)
		return;
	polynoms.erase(polynoms.begin() + index);
}

//���������� ���������
void VectPolynomial::Print() {
	for (int i = 0; i < Get_amount_of_polynomials(); i++) {
		polynoms.at(i).print();
	}
}