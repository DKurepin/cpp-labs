#include <iostream>
#include <stdexcept>

template <int N, class T>
class MaxNStack {
private:
    T data[N];
    int topIndex;
public:
    MaxNStack() : topIndex(-1) {}

    void push(const T& value) {
        if (topIndex >= N - 1) {
            throw std::overflow_error("Stack is full");
        }
        data[++topIndex] = value;
    }

    void pop() {
        if (topIndex < 0) {
            throw std::underflow_error("Stack is empty");
        }
        topIndex--;
    }

    T top() const {
        if (topIndex < 0) {
            throw std::underflow_error("Stack is empty");
        }
        return data[topIndex];
    }

    T getMax() const {
        if (topIndex < 0) {
            throw std::underflow_error("Stack is empty");
        }
        T max = data[0];
        for (int i = 1; i <= topIndex; i++) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;
    }

    bool empty() const {
        return topIndex < 0;
    }
};


