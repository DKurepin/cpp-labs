#include <stdexcept>
#include <string>

class StackException : public std::exception {
private:
    std::string message;
public:
    StackException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
