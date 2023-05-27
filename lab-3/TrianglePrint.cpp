#ifndef TRIANGLEPRINTER_H
#define TRIANGLEPRINTER_H

#include <iostream>
#include "Triangle.h"

class TrianglePrint {
public:
    static void print(const Triangle& tr) {
        std::cout << "(" << tr.getX1() << ", " << tr.getY1() << ")" << std::endl;
        std::cout << "(" << tr.getX2() << ", " << tr.getY2() << ")" << std::endl;
        std::cout << "(" << tr.getX3() << ", " << tr.getY3() << ")" << std::endl;
    }
};

#endif