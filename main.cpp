#include <iostream>

//#include "lab-1/Swap.h"
//#include "lab-1/Trunc.h"
//#include "Complex.h"
//#include "lab-1/Circle.h"
//#include "lab-1/Complex.h"
//#include "lab-2/Complex.h"
//#include "lab-3/Triangle.h"
//#include "lab-3/Int_Array.h"
#include "lab-4/ShapeSystem.cpp"
#include "lab-4/Circle.cpp"
#include "lab-4/EquilateralTriangle.cpp"


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


//    std::cout << "Enter a complex number (real and imaginary part): ";
//    double real, imag;
//    std::cin >> real >> imag;
//    Complex c1(real, imag);
//
//    std::cout << "Enter another complex number (real and imaginary part): ";
//    std::cin >> real >> imag;
//    Complex c2(real, imag);
//
//    std::cout << "Enter a scalar: ";
//    double scalar;
//    std::cin >> scalar;
//
//    Complex c3 = c1 + c2;
//    std::cout << "Sum of the two complex numbers: ";
//    c3.print();
//    Complex c4 = c1*c2;
//    std::cout << "Product of the two complex numbers: ";
//    c4.print();
//
//    Complex c5 = c1*scalar;
//    std::cout << "First complex number multiplied by scalar: ";
//    c5.print();
//
//    double length = c1.length();
//    std::cout << "Length of the first complex number: " << length << std::endl;


// --------- LAB-3 ---------

//    std::cout << "Enter coordinates of the first triangle: ";
//    double x1, y1, x2, y2, x3, y3;
//    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
//    Triangle t1(x1, y1, x2, y2, x3, y3);
//
//    std::cout << "Enter coordinates of the second triangle: ";
//    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
//    Triangle t2(x1, y1, x2, y2, x3, y3);
//
//    std::cout << "Enter vector coordinates (x, y): ";
//    double vx, vy;
//    std::cin >> vx >> vy;
//    std::pair<double, double> vec(vx, vy);
//
//    Triangle t3 = t1 + vec;
//    std::cout << "First triangle after adding the vector: ";
//    t3.print();
//
//    if (t1 == t2) {
//        std::cout << "The two triangles have the same area." << std::endl;
//    } else {
//        std::cout << "The two triangles have different areas." << std::endl;
//    }
//
//    if (t1 != t2) {
//        std::cout << "The two triangles have different areas." << std::endl;
//    } else {
//        std::cout << "The two triangles have the same area." << std::endl;
//    }
//
//    if (t1 < t2) {
//        std::cout << "The first triangle has a smaller area than the second." << std::endl;
//    } else if (t1 > t2) {
//        std::cout << "The first triangle has a larger area than the second." << std::endl;
//    } else {
//        std::cout << "The two triangles have the same area." << std::endl;
//    }
//
//
//    std::cout << "Enter the size of the first array: ";
//    int size1;
//    std::cin >> size1;
//    IntArray arr1(size1);
//    std::cout << "Enter the elements of the first array: ";
//    for (int i = 0; i < size1; i++) {
//        std::cin >> arr1[i];
//    }
//
//    std::cout << "Enter the size of the second array: ";
//    int size2;
//    std::cin >> size2;
//    IntArray arr2(size2);
//    std::cout << "Enter the elements of the second array: ";
//    for (int i = 0; i < size2; i++) {
//        std::cin >> arr2[i];
//    }
//
//    IntArray arr3 = arr1 + arr2;
//    std::cout << "The result of concatenating the two arrays: ";
//    arr3.print();
//
//    if (arr1 == arr2) {
//        std::cout << "The two arrays are equal." << std::endl;
//    } else {
//        std::cout << "The two arrays are not equal." << std::endl;
//    }
//
//    if (arr1 != arr2) {
//        std::cout << "The two arrays are not equal." << std::endl;
//    } else {
//        std::cout << "The two arrays are equal." << std::endl;
//    }
//
//    if (arr1 < arr2) {
//        std::cout << "The first array is shorter than the second." << std::endl;
//    } else if (arr1 > arr2) {
//        std::cout << "The first array is longer than the second." << std::endl;
//    } else {
//        std::cout << "The two arrays have the same length." << std::endl;
//    }


// --------- LAB-4 ---------

    ShapeSystem system;
    int choice = 0;
    while (choice != 9) {
        std::cout
                << "1. Add Circle\n2. Add Equilateral Triangle\n3. Total Area\n4. Total Perimeter\n5. Center of Mass"
                   "\n6. Get total memory\n7. Sort shapes by mass\n8. Display Shapes\n9. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                double radius, mass;
                std::cout << "Enter radius: ";
                std::cin >> radius;
                std::cout << "Enter mass: ";
                std::cin >> mass;
                system.addShape(new Circle(radius, mass));
                break;
            case 2:
                double sideLength, mass2;
                std::cout << "Enter length of each side: ";
                std::cin >> sideLength;
                std::cout << "Enter mass: ";
                std::cin >> mass2;
                system.addShape(new EquilateralTriangle(sideLength, mass2));
                break;
            case 3:
                std::cout << "Total area: " << system.getTotalArea() << "\n";
                break;
            case 4:
                std::cout << "Total perimeter: " << system.getTotalPerimeter() << "\n";
                break;
            case 5:
                std::cout << "Center of mass: " << system.getCenterOfMass() << "\n";
                break;
            case 6:
                system.getTotalMemory();
                break;
            case 7:
                system.sortShapesByMass();
                break;
            case 8:
                system.displayShapes();
                break;
            case 9:
                break;
            default:
                std::cout << "Invalid choice\n ";
        }
    }
    return 0;
}
