#ifndef COMPLEXH
#define COMPLEXH

struct Complex {
    double real;
    double imag;
};

void multiplyPointer(Complex num, double factor);
void multiplyReference(Complex& num, double factor);

#endif
