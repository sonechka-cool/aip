#include <iostream>
#include<cmath>
#include "header.h"
#define _USE_MATH_DEFINES
using namespace std;

// constructor by default 
Ellipse::Ellipse() {}



// constructor by parameters
Ellipse::Ellipse(double a, double b, double h, double k) {
    this->a = a;
    this->b = b;
    this->h = h;
    this->k = k;
    normalize_all();

}

// constructor by object copy
Ellipse::Ellipse(const Ellipse& e) {
    this->a = e.a;
    this->b = e.b;
    this->h = e.h;
    this->k = e.k;
    normalize_all();

}

//destructor
Ellipse::~Ellipse() {};

//procedure to normalize a and b
void Ellipse::normalize(double& a, double& b) {
    if (a < b) {
        double temp = a;
        a = b;
        b = temp;
    }
}
void Ellipse::normalize_all() {
    normalize( a, b);
}
//function for counting ellipsis hyperparameter c
double Ellipse::count_c(){
    return sqrt(pow(a, 2) - pow(b, 2));
}

// for getting coordinates of ellipse V1 and V2
void Ellipse::get_coordinates(double& x1, double& y1, double& x2, double& y2) {
    if (h > k) {
        x1 = h - a;
        y1 = k;
        x2 = h + a;
        y2 = k;
    }
    else {
        x1 = h;
        y1 = k - a;
        x2 = h;
        y2 = k + a;
    }
}

// procedure for getting coordinates of ellipse focus  F1 and F2 
void Ellipse::get_focus(double& x1, double& y1, double& x2, double& y2) {
    double c = count_c();
    if (h > k) {
        x1 = h - c;
        y1 = k;
        x2 = h + c;
        y2 = k;
    }
    else {
        x1 = h;
        y1 = k - c;
        x2 = h;
        y2 = k + c;
    }
}
// function for calculating length of focal chord
double Ellipse::calculate_fchord() {
    return (2 * b * b) / a;
}

// function for getting ellipse eccentricity 
double Ellipse::calculate_eccent() {
    double c = count_c();
    return c / a;
}

// setter for a,b,h,k
void Ellipse::set_all(double a, double b, double h, double k) {
    this->a = a;
    this->b = b;
    this->h = h;
    this->k = k;
}
//getter for a,b,h,k
void Ellipse::get_all(double& a, double& b, double& h, double& k) {
    a = this->a;
    b = this->b;
    h = this->h;
    k = this->k;
}

//procedure for printing ellipse parameters
void Ellipse::print_ellipse() {
    double c = count_c();
    double x1, x2, y1, y2;
    get_coordinates( x1, y1, x2, y2);
    double x3, x4, y3, y4;
    get_focus(x3, x4, y3, y4);
    cout << "Общее уравнение эллипса: " << endl;
    if (h > k) {
        cout << "((x - " << h << ")^2)/(" << a << "^2 ) + ((y - " << k << ")^2)/(" << b << "^2) = 1" << endl;
    }
    else {
        cout << "((x - " << h << ")^2)/(" << b << "^2 ) + ((y - " << k << ")^2)/(" << a << "^2) = 1" << endl;
    }
    cout << "Центр C: (" << h << "," << k << ")" << endl;
    cout << "Вершины V: (" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ")" << endl;
    cout << "Фокусы F: (" << x3 << "," << y3 << ") (" << x4 << "," << y4 << ")" << endl;
}
//functoin to check if P (x, y) is inside, on or outside the ellipse
void Ellipse::check_point(double x, double y) {
    
    if ((x * x) / (a * a) + (y * y) / (b*b) == 1) {
        cout << "Точка P(" << x << "," << y << ") лежит на эллипсе" << endl;
        
    }
    else if((x * x) / (a * a) + (y * y) / (b * b) < 1) {
        cout << "Точка P(" << x << "," << y << ") лежит внутри эллипса" << endl;
        
    }
    else {
        cout << "Точка P(" << x << "," << y << ") лежит вне эллипса" << endl;
        
    }
}
//function to calculate the perimeter of the ellipse
double Ellipse::perimeter() {
    return 3.14 * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}
//function to calculate the area of the ellipse
double Ellipse::area() {
    return 3.14 * a * b;
}
//procedure to get second coordinate
void Ellipse::get_second_coordinate() {
    int z;
    double x, y;
    cout << "Если хотите найти y, нажмите 1" << endl;
    cin >> z;
    if (z == 1) {
        cout << "Задайте координату x = " << endl;
        cin >> x;
        if (h > k) {
            y = sqrt(1 - ((x - h) * (x - h)) / (a * a)) * b + k;
        }
        else {
            y = sqrt(1 - ((x - h) * (x - h)) / (b * b)) * a + k;
        }
        cout << "Координата y = " << y << endl;
    }
    else {
        cout << "Задайте координату y = " << endl;
        cin >> y;
        if (h > k) {
            x = sqrt(1 - ((y - k) * (y - k)) / (b * b)) * a + h;
        }
        else {
            x = sqrt(1 - ((y - k) * (y - k)) / (a * a)) * b + h;
        }
        cout << "Координата x = " << x << endl;
    }
}





