#include "Swap.h"

void swapPointers(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapReferences(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
