#pragma once
class Ellipse {
private:

    double a, b, h, k;

public:
    Ellipse();
    Ellipse(double a, double b, double h=0, double k=0);
    Ellipse(const Ellipse& e);
    ~Ellipse();
    void normalize(double& a, double& b);
    void normalize_all();
    double count_c();
    void get_coordinates(double& x1, double& y1, double& x2, double& y2);
    void get_focus(double& x1, double& y1, double& x2, double& y2);
    double calculate_fchord();
    double calculate_eccent();
    void set_all(double a, double b, double h, double k);
    void get_all(double& a, double& b, double& h, double& k);
    void print_ellipse();
    void check_point(double x, double y);
    double perimeter();
    double area();
    void get_second_coordinate();
    

};