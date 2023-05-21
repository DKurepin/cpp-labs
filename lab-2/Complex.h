#ifndef COMPLEXH
#define COMPLEXH

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex();
    Complex(const Complex& other);
    Complex(double real, double imag);
    Complex(double real);

    Complex operator+(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator*(double scalar) const;

    double length() const;

    void print() const;

};

#endif
