#ifndef CIRCLEH
#define CIRCLEH

struct Point {
    int x;
    int y;
};

void shiftCirclePointer(Point center, int radius, int dx, int dy);
void shiftCircleReference(Point (&center), int radius, int dx, int dy);

#endif
