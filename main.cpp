#include <iostream>


#include <iostream>
//#include "lab-1/Swap.h"
//#include "lab-1/Trunc.h"
//#include "Complex.h"
//#include "lab-1/Circle.h"
//#include "lab-1/Complex.h"
#include "lab-2/Complex.h"

int main() {


//     --------- LAB-1 ---------

//
//    int x = 5, y = 10;
//    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
//
//    // Используем указатели
//    swapPointers(x, y);
//    std::cout << "After swap with pointers: x = " << x << ", y = " << y << std::endl;
//
//    // Используем ссылки
//    swapReferences(x, y);
//    std::cout << "After swap with references: x = " << x << ", y = " << y << std::endl;
//
//
//    double num = 3.14159;
//    std::cout << "Before truncation: " << num << std::endl;
//
//    // Используем указатель
//    truncPointer(&num);
//    std::cout << "After truncation with pointer: " << num << std::endl;
//
//    // Используем ссылку
//    truncReference(num);
//    std::cout << "After truncation with reference: " << num << std::endl;
//
//    Complex num2 = {3, 4};
//    std::cout << "Before multiplication: " << num2.real << " + " << num2.imag << "i" << std::endl;
//
//    // Используем указатель
//    multiplyPointer(num2, 2);
//    std::cout << "After multiplication with pointer: " << num2.real << " + " << num2.imag << "i" << std::endl;
//
//    // Используем ссылку
//    multiplyReference(num2, 0.5);
//    std::cout << "After multiplication with reference: " << num2.real << " + " << num2.imag << "i" << std::endl;
//
//
//    Point center = {0, 0};
//    int radius = 5;
//    std::cout << "Before shift: (" << center.x << ", " << center.y << ")" << std::endl;
//
//    // Используем указатель
//    shiftCirclePointer(center, radius, 3, -2);
//    std::cout << "After shift with pointer: (" << center.x << ", " << center.y << ")" << std::endl;
//
//    // Используем ссылку
//    shiftCircleReference(center, radius, -2, 1);
//    std::cout << "After shift with reference: (" << center.x << ", " << center.y << ")" << std::endl;
//

    // --------- LAB-2 ---------


    std::cout << "Enter a complex number (real and imaginary part): ";
    double real, imag;
    std::cin >> real >> imag;
    Complex c1(real, imag);

    std::cout << "Enter another complex number (real and imaginary part): ";
    std::cin >> real >> imag;
    Complex c2(real, imag);

    std::cout << "Enter a scalar: ";
    double scalar;
    std::cin >> scalar;

    Complex c3 = c1 + c2;
    std::cout << "Sum of the two complex numbers: ";
    c3.print();
    Complex c4 = c1*c2;
    std::cout << "Product of the two complex numbers: ";
    c4.print();

    Complex c5 = c1*scalar;
    std::cout << "First complex number multiplied by scalar: ";
    c5.print();

    double length = c1.length();
    std::cout << "Length of the first complex number: " << length << std::endl;


}
