#include <iostream>
#include "IntArray.h"

class IntArrayPrint {
public:
    static void print(const IntArray& arr) {
        if (arr.get_size() == 0) {
            std::cout << "Empty array" << std::endl;
            return;
        }
        for (int i = 0; i < arr.get_size(); i++) {
            std::cout << arr[i];
            if (i != arr.get_size() - 1) {
                std::cout << " ";
            }
            else {
                std::cout << std::endl;
            }
        }
    }
};
