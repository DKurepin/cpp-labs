#include <cmath>
#include "IShape.h"
#include "iostream"

class Circle : public IShape {
private:
    double radius;
    double mass;
    inline static const std::string TYPE = "Circle";

public:
    Circle(double r, double m) : radius(r), mass(m) {}

    double calculateArea() const override {
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

    inline std::string getType() const override {
        return TYPE;
    }
};