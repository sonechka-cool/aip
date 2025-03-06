#include<iostream>
#include<string>
#include<cmath>
#include"header.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	Ellipse el1;
	el1 = Ellipse(1, 3, 4, 5);
	el1.print_ellipse();
	cout << el1.count_c()<< endl;
	el1.check_point(5, 6);
	cout << el1.perimeter()<<endl;
	el1.get_second_coordinate();
	
}