#pragma once
#include <iostream>
#include <vector>
using namespace std;

class polynomial {
private:
	vector<double> A;//массив дл€ хранени€ коэфициентов
	vector<int> E;//массив дл€ хранени€ степеней

public:
	polynomial(int maxE, double* A);//конструктор по параметрам
	polynomial(int maxE);//конструктор по одному параметтру(по умолчанию)
	polynomial(const polynomial& p);//конструктор копировани€
	~polynomial();//деконструктор

	double getmax_E() const { return E.size(); };//возвращает максимальное значение ≈
	double get_A(int index) const;//возвращает значение по индексу
	void set_A(int index, double newA);//устанавливает новое значение ј по индексу
	void reset(int maxE, double* A);//cброс
	void print();//вывод
	double calculate(double x);//счЄт
};

polynomial operator+ (const polynomial & p1, const polynomial & p2);//оператор сложени€ двух объектов класса polynomial
polynomial operator- (const polynomial & p1, const polynomial & p2);//оператор вычетани€ двух объектов типа polynomial


class VectPolynomial {
private:
	vector<polynomial> polynoms;//тут храним объекты типа polynomial

public:
	VectPolynomial(polynomial& p);//конструктор 
	VectPolynomial(const VectPolynomial& vp);//конструктор копировани€
	~VectPolynomial();//деконструктор

	int Get_amount_of_polynomials() { return polynoms.size(); };//возвращает количество полиномов

	polynomial& Polynomial_ind(int index);//возвращает по индексу
	void Add_polynomial(polynomial& p) { polynoms.push_back(p); };//добавл€етновый
	void Remove_polynomial_ind(int index);//удал€ет по индексу

	void Print();
};