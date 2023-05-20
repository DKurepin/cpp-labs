#include <cmath>
#include "IShape.h"
#include "iostream"

class EquilateralTriangle : public IShape {
private:
    double sideLength;
    double mass;
    std::pair<double, double> center;
public:
    EquilateralTriangle(double sideLength, double mass)
            : sideLength(sideLength), mass(mass) {}

    double getArea() const override {
        return sqrt(3) / 4 * pow(sideLength, 2);
    }

    double getPerimeter() const override {
        return 3 * sideLength;
    }

    void print() const override {
        std::cout << "Type: Triangle\nLength of each side: " << sideLength << "\nMass: " << mass << "\n";
    }

    std::string getType() const override {
        return "Equilateral Triangle";
    }

    double getMass() const override {
        return mass;
    }
};
