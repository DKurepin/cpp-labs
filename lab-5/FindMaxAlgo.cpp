#include <algorithm>

template <typename T>
T findMax(const T* arr, int size) {
    if (size <= 0) {
        throw std::invalid_argument("Array size must be positive");
    }
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
