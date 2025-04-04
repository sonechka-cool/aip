#include "poly.h"
using namespace std;

//вызов конструктора по параметрам
polynomial::polynomial(int maxE, double* A) {
	//инициализируем многочлен,заполняя векторы А и Е
	for (int i = 0; i < maxE + 1; i++) {
		this->E.push_back(i);
		this->A.push_back(*(A + i));
	}
}

//вызов конструктора по умолчанию
polynomial::polynomial(int maxE) {
	//в вектор Е добавляем от 0 до макс Е, а вектор А заполнен нулями
	for (int i = 0; i < maxE + 1; i++) {
		this->E.push_back(i);
		this->A.push_back(0);
	}
}

//вызов конструктора копирования
polynomial::polynomial(const polynomial& p) {
	//заполняем значения
	for (int i = 0; i < p.E.size(); i++) {
		this->E.push_back(i);
		this->A.push_back(p.A.at(i));
	}
}
//деконструктор
polynomial::~polynomial() {
}

//получение значения по коэфициенту
double polynomial::get_A(int index) const {
	//проверяем границы 
	if (index >= getmax_E() || index < 0)
		return 0;
	return A.at(index);
}

//значение по заданному индексу
void polynomial::set_A(int index, double newA) {
	//проверка допустимого
	if (index < 0)
		return;
	//заполняем вектора
	while (index >= getmax_E()) {
		E.push_back(getmax_E());
		A.push_back(0);
	}
	//устанавливаем новое значение
	A.at(index) = newA;
}

//обновление векторов
void polynomial::reset(int maxE, double* A) {
	//удалянм старые данные
	this->E.clear();
	this->A.clear();
	//добавляем новые данные
	for (int i = 0; i < maxE + 1; i++) {
		this->E.push_back(i);
		this->A.push_back(*(A + i));
	}
}

//вывод многочлена на экран
void polynomial::print() {
	//определяем количество элементов в векторе Е
	int n = E.size();
	//отслеживаем напечатан ли нулевой член
	bool is_first_printed = false;
	//проходимся по всем коэфициентам до n
	for (int i = 0; i < n; i++) {
		double Ai = A.at(i);
		//если коэфициент равен 0, то идём дальше
		if (Ai == 0)
			continue;
		//если это не нулевой коэф, то решаем вопрос со знаком
		if (is_first_printed) {
			if (Ai > 0) {
				cout << " + ";
			}
			if (Ai < 0) {
				cout << " - ";
				Ai *= -1;
			}
		}
		//если коэф не равен 1 или он первый, то печатаем его
		if (Ai != 1 || i == 0) {
			cout << Ai;
		}

		//теперь первый коэфициент у нас напечатан-эотот этап выполнен-true
		is_first_printed = true;
		//если это не нулевой член, то добавляем x
		if (i != 0)
			cout << "x";
		if (i > 1)//добавляем степень
			cout << "^" << E.at(i);
	}
	cout << endl;
}

//вычисляем значение для данного многочлена
double polynomial::calculate(double x) {
	//инициализируем первм коэфициентом
	double f = get_A(0);
	//вычисляем степень
	int n = getmax_E() + 1;
	//вычисляем значение многочлена
	for (int i = 1; i < n; i++) {
		f += get_A(i) * pow(x, i);
	}
	return f;
}

//складываем 2 многочлена
polynomial operator+ (const polynomial& p1, const polynomial& p2) {
	//определяем максимальную степень
	int maxE = p1.getmax_E() >= p2.getmax_E() ? p2.getmax_E() : p1.getmax_E();
	//создаем новый многочлен с максимальной степенью
	polynomial f(maxE);

	//суммиуем соответствующие коэф
	for (int i = 0; i < maxE + 1; i++) {
		f.set_A(i, p1.get_A(i) + p2.get_A(i));
	}
	return f;
}


//вычетание. аналогично сложению
polynomial operator- (const polynomial& p1, const polynomial& p2) {
	int maxE = p1.getmax_E() >= p2.getmax_E() ? p1.getmax_E() : p2.getmax_E();
	polynomial f(maxE);

	for (int i = 0; i < maxE + 1; i++) {
		f.set_A(i, p1.get_A(i) - p2.get_A(i));
	}
	return f;
}

//конструктор копирования
VectPolynomial::VectPolynomial(polynomial& p) {
	polynoms.push_back(p);
}
VectPolynomial::VectPolynomial(const VectPolynomial& vp) {
	for (int i = 0; i < polynoms.size(); i++) {
		polynoms.push_back(vp.polynoms.at(i));
	}
}
//деструктор
VectPolynomial::~VectPolynomial() {

}

//удаление элемента по индексу
void VectPolynomial::Remove_polynomial_ind(int index) {
	if (index < 0 || index > Get_amount_of_polynomials() - 1)
		return;
	polynoms.erase(polynoms.begin() + index);
}

//количество полиномов
void VectPolynomial::Print() {
	for (int i = 0; i < Get_amount_of_polynomials(); i++) {
		polynoms.at(i).print();
	}
}