#include <iostream>
#include "poly.h"
using namespace std;
int main()
{
	srand(1);//инициализируем генератор случайных чисел
	double M1[4] = { 0, 0, 0, 0 };//создаем массив коэфициентов
	for (int j = 0; j < 4; j++) {//заполняем массив случайными числами
		M1[j] = rand() % 21 - 10;//присваиваем каждому элементу его значение
	}

	polynomial P1(3, M1);//вызываем конструктор для полиноиа 3ей степени с коэфициентами из массива М
	VectPolynomial V1(P1);//создается объект с полиномом Р1 в качестве начального объекта
	//цикл для создания нвого полинома
	for (int i = 0; i < 3; i++) {
		double m[4] = { 0, 0, 0, 0 };
		for (int j = 0; j < 4; j++) {
			m[j] = rand() % 21 - 10;
		}
		//добавляем полином в список
		polynomial ip(3, m);
		V1.Add_polynomial(ip);
	}
	//вывод полиномов V1
	V1.Print();
	cout << endl;

	double M2[4] = { 0, 0, 0, 0 };
	for (int j = 0; j < 4; j++) {
		M2[j] = rand() % 21 - 10;
	}
	//создание полинома Р2 и вектора V2
	polynomial P2(3, M2);
	VectPolynomial V2(P2);
	for (int i = 0; i < 3; i++) {
		double m[4] = { 0, 0, 0, 0 };
		for (int j = 0; j < 4; j++) {
			m[j] = rand() % 21 - 10;
		}
		//добавляем полином в список
		polynomial ip(3, m);
		V2.Add_polynomial(ip);
	}

	V2.Print();
	cout << endl;
};
//ДОДЕЛАТЬ С V3 И V4