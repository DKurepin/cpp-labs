#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <iostream>

class IntArray {
private:
    int* data;
    int size;

public:
    IntArray();
    IntArray(int size);
    IntArray(const IntArray& other);
    ~IntArray();

    IntArray operator+(const IntArray& other) const;
    bool operator==(const IntArray& other) const;
    bool operator!=(const IntArray& other) const;
    bool operator<(const IntArray& other) const;
    bool operator>(const IntArray& other) const;

    int& operator[](int index);
    const int& operator[](int index) const;

    int get_size() const;

    void print() const;
};

#endif
