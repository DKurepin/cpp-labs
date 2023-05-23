#include <iostream>
#include <vector>
#include <array>

//#include "lab-1/Swap.h"
//#include "lab-1/Trunc.h"
//#include "lab-1/Circle.h"
//#include "lab-1/Complex.h"
//#include "lab-2/Complex.h"
//#include "lab-3/Triangle.h"
//#include "lab-3/Int_Array.h"
//#include "lab-4/ShapeSystem.cpp"
//#include "lab-4/Circle.cpp"
//#include "lab-4/EquilateralTriangle.cpp"
//#include "lab-5/MaxNStack.cpp"
//#include "lab-6/Algorithms.h"
//#include "lab-7/circular_buffer.h"
#include "lab-8/Cube.h"
#include "lab-8/CubeAlgorithm.cpp"
#include "lab-8/CubePrint.cpp"

template<typename T>
bool sorted(T a, T b) {
    if (a <= b)
        return true;
    return false;
}

template<typename T>
bool greater(T a) {
    if (a > 10)
        return true;
    return false;
}

template<typename T>
bool func(T a, T b) {
    if (a == b)
        return true;
    return false;
}


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

//    ShapeSystem system;
//    int choice = 0;
//    while (choice != 9) {
//        std::cout
//                << "1. Add Circle\n2. Add Equilateral Triangle\n3. Total Area\n4. Total Perimeter\n5. Center of Mass"
//                   "\n6. Get total memory\n7. Sort shapes by mass\n8. Display Shapes\n9. Exit\n";
//        std::cin >> choice;
//        switch (choice) {
//            case 1:
//                double radius, mass;
//                std::cout << "Enter radius: ";
//                std::cin >> radius;
//                std::cout << "Enter mass: ";
//                std::cin >> mass;
//                system.addShape(new Circle(radius, mass));
//                break;
//            case 2:
//                double sideLength, mass2;
//                std::cout << "Enter length of each side: ";
//                std::cin >> sideLength;
//                std::cout << "Enter mass: ";
//                std::cin >> mass2;
//                system.addShape(new EquilateralTriangle(sideLength, mass2));
//                break;
//            case 3:
//                std::cout << "Total area: " << system.getTotalArea() << "\n";
//                break;
//            case 4:
//                std::cout << "Total perimeter: " << system.getTotalPerimeter() << "\n";
//                break;
//            case 5:
//                std::cout << "Center of mass: " << system.getCenterOfMass() << "\n";
//                break;
//            case 6:
//                system.getTotalMemory();
//                break;
//            case 7:
//                system.sortShapesByMass();
//                break;
//            case 8:
//                system.displayShapes();
//                break;
//            case 9:
//                break;
//            default:
//                std::cout << "Invalid choice\n ";
//        }
//    }

// --------- LAB-5 ---------
//
//    MaxNStack<3, int> s;
//    try {
//        s.pop();
//    } catch (const std::exception& e) {
//        std::cout << "Exception: " << e.what() << std::endl;
//    }
//    try {
//        s.push(1);
//        std::cout << "Max: " << s.getMax() << std::endl;
//        s.push(2);
//        std::cout << "Max: " << s.getMax() << std::endl;
//        s.push(3);
//        std::cout << "Max: " << s.getMax() << std::endl;
//        s.push(4);
//    } catch (const std::exception& e) {
//        std::cout << "Exception: " << e.what() << std::endl;
//    }
//    try {
//        std::cout << "Top: " << s.top() << std::endl;
//        s.pop();
//        std::cout << "Max: " << s.getMax() << std::endl;
//        s.pop();
//        std::cout << "Max: " << s.getMax() << std::endl;
//        s.pop();
//        std::cout << "Max: " << s.getMax() << std::endl;
//        s.pop();
//    } catch (const std::exception& e) {
//        std::cout << "Exception: " << e.what() << std::endl;
//    }
//    return 0;


// --------- LAB-6 ---------

//    std::vector<int> vec;
//    vec.push_back(0);
//    vec.push_back(0);
//    vec.push_back(0);
//    vec.push_back(0);
//    vec.push_back(1);
//    std::cout << is_Sorted(vec.begin(), vec.end(), sorted<int>) << std::endl;
//    // Выведет 1, так как вектор отсортирован по возрастанию
//
//    std::array<int, 5> arr = {100, 200, 30, 40, 51};
//    std::cout << All_of(arr.begin(), arr.end(), greater<int>) << std::endl;
//    // Выведет 1, так как все элементы массива больше 10
//
//    std::vector<int> vec1;
//    vec1.push_back(1);
//    vec1.push_back(2);
//    vec1.push_back(1);
//    std::cout << is_Palindrome(vec1.begin(), vec1.end(), func<int>) << std::endl;
//    // Выведет 1, так как вектор является палиндромом
//
//    return 0;

// --------- LAB-7 ---------

//    circular_buffer<int> test(7, 20);
//    for (int i = 0; i < 7; ++i)
//        test.append(i);
//    for (int i = 0; i < 7; ++i)
//        std::cout << test[i];
//    std::cout << std::endl;
//    test.append(7);
//    for (auto it = test.begin(); it != test.end(); ++it)
//        std::cout << *it;
//    std::cout << '\n';
//    std::cout << test.pop_from_start() << '\n' << test.pop() << '\n';
//    test.append_to_start(1);
//    for (int i = 0; i < 7; ++i)
//        std::cout << test[i];
//    return 0;

// --------- LAB-8 ---------

    // enum для того, чтобы просто было видно какие команды существуют
    enum Rotations {
        F, F_, B, B_,
        R, R_, L, L_,
        U, U_, D, D_,
        D2, U2, L2, R2,
        B2, F2, lp, rp,
        lp_, rp_, horizontalRotateL, horizontalRotate
    };


    int choice = 0;
    Cube currentCube;
    while (choice != 8) {
        std::cout
                << "1. Add new Rubik Cube\n2. Randomize Rubik Cube\n3. Read from file and Solve\n4. Solve Rubik Cube\n5. Print Rubik Cube\n6. Write solution to file\n7. Enter your commands\n8. Exit\n";

        std::cin >> choice;
        switch (choice) {
            case 1: {
                Cube *cube1 = new Cube();
                currentCube = *cube1;
                CubePrint::print(currentCube);
            }
                break;
            case 2: {
                Cube *cube2 = new Cube();
                cube2->generateRandomCube();
                currentCube = *cube2;
                CubePrint::print(currentCube);
            }
                break;
            case 3: {
                std::ifstream in("/Users/DNK/Desktop/cpp-labs/input.txt");
                Cube *cube = new Cube(in);
                in.close();
                currentCube = *cube;
                CubePrint::print(currentCube);
            }
                break;
            case 4: {
                CubeAlgorithm::solve(currentCube);
                CubePrint::print(currentCube);
            }
                break;
            case 5: {
                CubePrint::print(currentCube);
            }
                break;
            case 6: {
                currentCube.answers_output();
            }
                break;
            case 7: {
                std::string command;
                std::cout << "Enter your commands: ";
                std::cin >> command;
                while (command != "quit") {
                    if (command == "F") {
                        currentCube.F();
                    } else if (command == "B") {
                        currentCube.B();
                        CubePrint::print(currentCube);
                    } else if (command == "B_") {
                        currentCube.B_();
                        CubePrint::print(currentCube);
                    } else if (command == "F") {
                        currentCube.F();
                        CubePrint::print(currentCube);
                    } else if (command == "F_") {
                        currentCube.F_();
                        CubePrint::print(currentCube);
                    } else if (command == "U") {
                        currentCube.U();
                        CubePrint::print(currentCube);
                    } else if (command == "U_") {
                        currentCube.U_();
                        CubePrint::print(currentCube);
                    } else if (command == "D") {
                        currentCube.D();
                        CubePrint::print(currentCube);
                    } else if (command == "D_") {
                        currentCube.D_();
                        CubePrint::print(currentCube);
                    } else if (command == "L") {
                        currentCube.L();
                        CubePrint::print(currentCube);
                    } else if (command == "R") {
                        currentCube.R();
                        CubePrint::print(currentCube);
                    } else if (command == "R_") {
                        currentCube.R_();
                        CubePrint::print(currentCube);
                    } else if (command == "L_") {
                        currentCube.L_();
                        CubePrint::print(currentCube);
                    } else if (command == "B2") {
                        currentCube.B2();
                        CubePrint::print(currentCube);
                    } else if (command == "D2") {
                        currentCube.D2();
                        CubePrint::print(currentCube);
                    } else if (command == "R2") {
                        currentCube.R2();
                        CubePrint::print(currentCube);
                    } else if (command == "U2") {
                        currentCube.U2();
                        CubePrint::print(currentCube);
                    } else if (command == "lp") {
                        currentCube.lp();
                        CubePrint::print(currentCube);
                    } else if (command == "lp_") {
                        currentCube.lp_();
                        CubePrint::print(currentCube);
                    } else if (command == "rp_") {
                        currentCube.rp_();
                        CubePrint::print(currentCube);
                    } else if (command == "rp") {
                        currentCube.rp();
                        CubePrint::print(currentCube);
                    } else if (command == "Horizontal Rotate L") {
                        currentCube.horizontalRotateL();
                        CubePrint::print(currentCube);
                    } else if (command == "Horizontal Rotate") {
                        currentCube.horizontalRotate();
                        CubePrint::print(currentCube);
                    } else {
                        std::cout << "Invalid command!" << std::endl;
                        break;
                    }
                    std::cout << "Enter command: ";
                    std::cin >> command;
                }
            }
            case 8:
                break;
            default:
                std::cout << "Invalid choice\n ";
        }
    }
}
