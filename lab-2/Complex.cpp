#include "complex.h"
#include <cmath>

Complex::Complex() : real(0), imag(0) {}

Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex::Complex(double real) : real(real), imag(0) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator*(const Complex& other) const {
double newReal = real*other.real - imag*other.imag;
double newImag = real*other.imag + imag*other.real;
return Complex(newReal, newImag);
}

Complex Complex::operator*(double scalar) const {
return Complex(real*scalar, imag*scalar);
}

double Complex::length() const {
    return std::sqrt(real*real + imag*imag);
}

void Complex::print() const {
    std::cout << real << " + " << imag << "i" << std::endl;
}
