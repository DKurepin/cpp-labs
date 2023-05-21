#include "Trunc.h"

void truncPointer(double* num) {
    *num = static_cast<int>(*num);
}

void truncReference(double& num) {
    num = static_cast<int>(num);
}
