#ifndef EquilateralTriangle_h
#define EquilateralTriangle_h

#include <cmath>
#include "IShape.h"
#include "iostream"

class EquilateralTriangle : public IShape {
private:
    double sideLength;
    double mass;
    std::pair<double, double> center;
    inline static const std::string TYPE = "Equilateral Triangle";


public:
    EquilateralTriangle(double sideLength, double mass)
            : sideLength(sideLength), mass(mass) {}

    double calculateArea() const override {
        return sqrt(3) / 4 * pow(sideLength, 2);
    }

    double getPerimeter() const override {
        return 3 * sideLength;
    }

    void print() const override {
        std::cout << "Type: Triangle\nLength of each side: " << sideLength << "\nMass: " << mass << "\n";
    }

    inline std::string getType() const override {
        return TYPE;
    }

    double getMass() const override {
        return mass;
    }
};

#endif