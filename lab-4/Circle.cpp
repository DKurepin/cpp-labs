#include <cmath>
#include "IShape.h"
#include "iostream"

class Circle : public IShape {
private:
    double radius;
    double mass;
public:
    Circle(double r, double m) : radius(r), mass(m) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * M_PI * radius;
    }

    void print() const override {
        std::cout << "Type: Circle\nRadius: " << radius << "\nMass: " << mass << "\n";
    }

    double getMass() const override {
        return mass;
    }

    std::string getType() const override {
        return "Circle";
    }
};