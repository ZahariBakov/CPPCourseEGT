#pragma once

//Advanced Features :
//	Explain the concept of templates in C++ and how they support generic
//	programming.Include a simple example of a template function.
//
//	Темплейтите в C++  позволяват създаването на функции и класове, които работят, без да са обвързани с конкретен тип данни.
//	Темплейтите позволяват на функциите да работят с всички типове данни. 
//	Те позволяват дефинирането на функции или класове с един или повече общи параметри на тип.
//
//	Templates in C++ allow the creation of functions and classes that operate without being bound to a specific data type.
//	Templates allow functions to work with all data types. 
//	They allow functions or classes to be defined with one or more generic type parameters.
//
// Example:

//#include <iostream>
//
//// Template function that find maximum of two numbers
//template <typename T>
//T max(T a, T b) {
//    return (a > b) ? a : b;
//}
//
//int main() {
//    // Instantiation with int
//    int intMax = max(10, 20);
//
//    // Instantiation with double
//    double doubleMax = max(3.14, 2.71);
//
//    std::cout << "Maximum of 10 and 20: " << intMax << std::endl;
//    std::cout << "Maximum of 3.14 and 2.71: " << doubleMax << std::endl;
//
//    return 0;
//}

