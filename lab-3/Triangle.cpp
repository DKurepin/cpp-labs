#include "triangle.h"
#include <cmath>

Triangle::Triangle() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0) {}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) :
        x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

Triangle::Triangle(const Triangle &other) :
        x1(other.x1), y1(other.y1),
        x2(other.x2), y2(other.y2),
        x3(other.x3), y3(other.y3) {}

Triangle Triangle::operator+(const std::pair<double, double> &vec) const {
    return Triangle(x1 + vec.first, y1 + vec.second,
                    x2 + vec.first, y2 + vec.second,
                    x3 + vec.first, y3 + vec.second);
}

bool Triangle::operator==(const Triangle &other) const {
    return std::abs(area() - other.area()) < 1e-9;
}

bool Triangle::operator!=(const Triangle &other) const {
    return !(this->operator==(other));
}

bool Triangle::operator<(const Triangle &other) const {
    return area() < other.area();
}

bool Triangle::operator>(const Triangle &other) const {
    return area() > other.area();
}

double Triangle::area() const {
    static double s = -1;
    if (s == -1) {
        double a = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        double b = std::sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        double c = std::sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        double p = (a + b + c) / 2;
        s = std::sqrt(p * (p - a) * (p - b) * (p - c));
    }
    return s;
}

double Triangle::getX1() const {
    return x1;
}

double Triangle::getY1() const {
    return y1;
}

double Triangle::getX2() const {
    return x2;
}

double Triangle::getY2() const {
    return y2;
}

double Triangle::getX3() const {
    return x3;
}

double Triangle::getY3() const {
    return y3;
}

