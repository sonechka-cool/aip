#include <iostream>
#include <cmath>
#include "quaternion.h"
using namespace std;

//constructor by parameters + per default
Quaternion::Quaternion(double a, double b, double c, double d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;

}
//constuctor by object copy
Quaternion::Quaternion(const Quaternion& q) {
    this->a = q.a;
    this->b = q.b;
    this->c = q.c;
    this->d = q.d;
}
//destructor

Quaternion::~Quaternion(){}

//setter for a, b, c, d
void Quaternion::set_all(double a, double b, double c, double d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

//getter for a, b, c, d
void Quaternion::get_all(double& a, double& b, double& c, double& d) {
    a = this->a;
    b = this->b;
    c = this->c;
    d = this->d;
}

//procedure for printing quternion
void Quaternion::print() {
    cout << "q = " << a << " + " << b << "i + " << c << "j + " << d << "k" << endl;
}
//function for calculating quaternion norm
double Quaternion::norm() {
    return sqrt(a * a + b * b + c * c + d * d);
}
//procedure for getting conjugate quaternion
void Quaternion::conjugate() {
    cout << "q = " << a << " - " << b << "i - " << c << "j - " << d << "k" << endl;
}

//procedure for quaternion normalization
void Quaternion::normalize() {
    double n = sqrt(a * a + b * b + c * c + d * d);
    a = a / n;
    b = b / n;
    c = c / n;
    d = d / n;
    cout << "q = " << a << " + " << b << "i + " << c << "j + " << d << "k" << endl;
}
//procedure for getting quaternion inversion
void Quaternion::inverse() {
    double n = sqrt(a * a + b * b + c * c + d * d);
    a /= n * n;
    b /= n * n;
    c /= n * n;
    d /= n * n;
    cout << "q = " << a << " + " << b << "i + " << c << "j + " << d << "k";
}
//function for calculating evclide distance
double Quaternion::evclide_distance(Quaternion q1, Quaternion q2) {
    return sqrt(pow(q1.a - q2.a, 2) + pow(q1.b - q2.b, 2) + pow(q1.c - q2.c, 2) + pow(q1.d - q2.d, 2));
}
//function for calculating chebyshev norm
double Quaternion::norm_cheb(Quaternion q1, Quaternion q2) {
    return max(max(abs(q1.a - q2.a), abs(q1.b - q2.b)), max(abs(q1.c - q2.c), abs(q1.d - q2.d)));
}


//            --- Global Operations ---
// function to calculate sum of two quaternions
Quaternion sum(Quaternion q1, Quaternion q2) {
    return Quaternion(q1.a + q2.a, q1.b + q2.b, q1.c + q2.c, q1.d + q2.d);
}

// function to calculate difference of two quaternions
Quaternion difference(Quaternion q1, Quaternion q2) {
    return Quaternion(q1.a - q2.a, q1.b - q2.b, q1.c - q2.c, q1.d - q2.d);
}
// function to calculate product of two quaternions
Quaternion product(Quaternion q1, Quaternion q2) {
    Quaternion q3;
    q3.a = q1.a * q2.a - q1.b * q2.b - q1.c * q2.c - q1.d * q2.d;
    q3.b = q1.a * q2.b + q1.b * q2.a + q1.c * q2.d - q1.d * q2.c;
    q3.c = q1.a * q2.c - q1.b * q2.d + q1.c * q2.a + q1.d * q2.b;
    q3.d = q1.a * q2.d + q1.b * q2.c - q1.c * q2.b + q1.d * q2.a;
    return q3;
}

// function to calculate division of two quaternions
Quaternion division(Quaternion q1, Quaternion q2) {
    q2.inverse();
    return product(q1, q2);
}

//scalar product of two quaternions
Quaternion scalar_product(Quaternion q1, Quaternion q2) {
    return Quaternion(q1.a * q2.a + q1.b * q2.b + q1.c * q2.c + q1.d * q2.d, 0, 0, 0);
}