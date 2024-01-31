#pragma once

//STL Containers :
//	Write about the purpose and use of the std::vector container in C++.
//
//	Вектора позволява съхраняването на променлив брой елементи и размерът му се регулира по време на изпълнение. 
//	Това го прави подходящ за ситуации, при които броят на елементите не е известен по време на компилиране или 
//	може да се промени с времето. 
//	Той съхранява елементите си в съседни места в паметта, което позволява да се прави и пойнтър аритметика. 
//	Елементите му могат да се достъпват чрез индекси.Постоянно увеличава размера си щом бъде запълнен. 
//	Той е може би най - използваният вид контейнер в С++.
//
//	A vector allows storing a variable number of elements and its size is update at runtime.
//	This makes it suitable for situations where the number of elements is unknown at compile time or may change over time. 
//	It stores its elements in next locations in memory, allowing pointer arithmetic to be done. 
//	His elements can be accessed by indexes.It constantly increases in size as it fills up. 
//	It is probably the most used type of container in C++.
//
// Example:

//#include <iostream>
//#include <vector>
//
//int main() {
//
//    // Create a vector of int
//    std::vector<int> vec;
//
//    // Add elements to the vector
//    vec.push_back(10);
//    vec.push_back(20);
//    vec.push_back(30);
//
//    // Output elements by index
//    std::cout << "First element at index 0: " << vec[0] << std::endl;
//    std::cout << "Second element at index 1: " << vec[1] << std::endl;
//    std::cout << "Third element at index 2: " << vec[2] << std::endl;
//
//    // Iterate over the vector using iterators
//    std::cout << "Vector elements: ";
//    for (auto it = vec.begin(); it != vec.end(); ++it) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

