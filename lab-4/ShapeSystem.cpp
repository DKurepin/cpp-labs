#include "iostream"
#include <vector>
#include "IShape.h"

class ShapeSystem {
private:
    std::vector<IShape *> shapes;
public:
    ~ShapeSystem() {
        for (auto shape: shapes) {
            delete shape;
        }
    }

    void addShape(IShape *shape) {
        shapes.push_back(shape);
    }

    void displayShapes() const {
        for (auto shape: shapes) {
            shape->print();
        }
    }

    double getTotalArea() const {
        double totalArea = 0;
        for (auto shape: shapes) {
            totalArea += shape->getArea();
        }
        return totalArea;
    }

    double getTotalPerimeter() const {
        double totalPerimeter = 0;
        for (auto shape: shapes) {
            totalPerimeter += shape->getPerimeter();
        }
        return totalPerimeter;
    }

    double getCenterOfMass() const {
        double totalMass = 0;
        double centerOfMass = 0;
        for (auto shape: shapes) {
            totalMass += shape->getMass();
            centerOfMass += shape->getMass() * shape->getPerimeter();
        }
        if (totalMass != 0) {
            centerOfMass /= totalMass;
        }
        return centerOfMass;
    }

    void getTotalMemory() {
        double totalMemory = 0;
        for (auto shape: shapes) {
            totalMemory += sizeof(*shape);
        }
        std::cout << "Total memory: " << totalMemory << "\n";
    }

    void sortShapesByMass() {
        std::sort(shapes.begin(), shapes.end(), [](IShape *a, IShape *b) { return a->getMass() < b->getMass(); });
        for (auto shape: shapes) {
            shape->print();
        }
    }
};
