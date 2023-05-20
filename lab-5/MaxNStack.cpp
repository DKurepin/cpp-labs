#include <iostream>
#include <stack>
#include <stdexcept>

template <int N, class T>
class MaxNStack {
private:
    std::stack<T> s;
    std::stack<T> maxStack;
public:
    void push(const T& value) {
        if (s.size() == N) {
            throw std::overflow_error("Stack is full");
        }
        s.push(value);
        if (maxStack.empty() || value >= maxStack.top()) {
            maxStack.push(value);
        }
    }
    void pop() {
        if (s.empty()) {
            throw std::underflow_error("Stack is empty");
        }
        if (s.top() == maxStack.top()) {
            maxStack.pop();
        }
        s.pop();
    }
    T top() const {
        if (s.empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return s.top();
    }
    T getMax() const {
        if (maxStack.empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return maxStack.top();
    }
    bool empty() const {
        return s.empty();
    }
};
