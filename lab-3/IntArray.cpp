#include "IntArray.h"
#include <cstring>

IntArray::IntArray() : data(nullptr), size(0) {}

IntArray::IntArray(int size) : data(new int[size]), size(size) {
    std::memset(data, 0, size * sizeof(int));
}

IntArray::IntArray(const IntArray& other) : data(new int[other.size]), size(other.size) {
    std::memcpy(data, other.data, size * sizeof(int));
}

IntArray::~IntArray() {
    delete[] data;
}

IntArray IntArray::operator+(const IntArray& other) const {
    IntArray result(size + other.size);
    std::memcpy(result.data, data, size * sizeof(int));
    std::memcpy(result.data + size, other.data, other.size * sizeof(int));
    return result;
}

bool IntArray::operator==(const IntArray& other) const {
    if (this == &other) {
        return true;
    }
    if (size != other.size) {
        return false;
    }
    if (data == other.data) {
        return true;
    }
    for (int i = 0; i < size; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool IntArray::operator!=(const IntArray& other) const {
    return !(*this == other);
}

bool IntArray::operator<(const IntArray& other) const {
    return size < other.size;
}

bool IntArray::operator>(const IntArray& other) const {
    return size > other.size;
}

int& IntArray::operator[](int index) {
    return data[index];
}

const int& IntArray::operator[](int index) const {
    return data[index];
}

int IntArray::get_size() const {
    return size;
}

