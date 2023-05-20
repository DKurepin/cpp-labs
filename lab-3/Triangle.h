#ifndef TRIANGLEH
#define TRIANGLEH

#include <iostream>

class Triangle {
private:
    double x1, y1;
    double x2, y2;
    double x3, y3;

public:
    Triangle();
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
    Triangle(const Triangle& other);

    Triangle operator+(const std::pair<double, double>& vec) const;
    bool operator==(const Triangle& other) const;
    bool operator!=(const Triangle& other) const;
    bool operator<(const Triangle& other) const;
    bool operator>(const Triangle& other) const;

    double area() const;

    void print() const;
};

#endif
