#include "circle.h"
#include <cmath>

void shiftCirclePointer(Point center, int radius, int dx, int dy) {
    center.x += dx;
    center.y += dy;
}

void shiftCircleReference(Point (&center), int radius, int dx, int dy) {
    center.x += dx;
    center.y += dy;
}
