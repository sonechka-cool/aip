#include <iostream>
#include <cmath>
#include "quaternion.h"

using namespace std;

int main() {
	Quaternion q; //create object with parameters per default
	q.print();
	Quaternion q2 = Quaternion(1.0, 2.0, 1.0, 2.0); // create object by parameters
	q2.print();
	Quaternion q3 = Quaternion(q2); // create object by copy
	q3.print();
	q3.set_all(2.0, 3.0, 1.0, 2.0);
	cout<< "q3 after update using setters:" << endl;
	q3.print();
	// return data with getters
	double a3, b3, c3, d3;
	q3.get_all(a3, b3, c3, d3);
	cout << "-- variables from getters -- " << endl;
	cout << "a3: " << a3 << endl;
	cout << "b3: " << b3 << endl;
	cout << "c3: " << c3 << endl;
	cout << "d3: " << d3 << endl;
	double norm;
	norm = q3.norm();
	cout << "norm of q3: " << norm << endl;
	cout << "q3 conjugate: ";
	q3.conjugate();
	cout << "normalized q3: ";
	q3.normalize();
	cout << "inversed q3: ";
	q3.inverse();
	
}