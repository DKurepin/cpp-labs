#ifndef IShape_h
#define IShape_h

#include <string>

class IShape {
public:
    virtual double calculateArea() const = 0;

    virtual double getPerimeter() const = 0;

    virtual void print() const = 0;

    virtual double getMass() const = 0;

    virtual std::string getType() const = 0;

    virtual ~IShape() {}
};

#endif