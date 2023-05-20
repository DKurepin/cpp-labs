
#include "Complex.h"

void multiplyPointer(Complex num, double factor) {
    num.real = factor;
    num.imag = factor;
}

void multiplyReference(Complex& num, double factor) {
    num.real = factor;
    num.imag = factor;
}
