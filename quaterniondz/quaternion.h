#pragma once
class Quaternion {

public:

    double a, b, c, d;

public:
    Quaternion(double a = 1.0, double b = 0.0, double c = 0.0, double d = 0.0);
    Quaternion(const Quaternion& q);
    ~Quaternion();
    void set_all(double a, double b, double c, double d);
    void get_all(double& a, double& b, double& c, double& d);
    void print();
    double norm();
    void conjugate();
    void normalize();
    void inverse();
    static double evclide_distance(Quaternion q1, Quaternion q2);
    static double norm_cheb(Quaternion q1, Quaternion q2);

    
};
    
Quaternion sum(Quaternion q1, Quaternion q2);
Quaternion difference(Quaternion q1, Quaternion q2);
Quaternion product(Quaternion q1, Quaternion q2);
Quaternion scalar_product(Quaternion q1, Quaternion q2);


