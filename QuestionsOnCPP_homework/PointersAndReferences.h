#pragma once

//Pointers and References:
//	Discuss the differece between poiters and references in C++ and
//	provide scenarios where one might be preferred over the other.
//
//	Пойнтъра се дефинира с "*" пред името му.Той сочи към адреса на паметта на друга променлива.
//	Референцията се дефинира с "&" пред името.Тя подава адреса на паметта на конкретната променлива.
//
//	Референцията подава адреса на текущата променлива, а пойнтъра държи адреса и го подава на функции или цилки, 
//		където пойнтъра се разопакова и се взима стойността на променливата на този адрес.
//
//	Pointer is defined with a "*" in front of its name.It points to the memory address of another variable.
//	Reference is defined with "&" in front of the name.It gives the memory address of the particular variable.
//
//	The reference passes the address of the current variable, and the pointer stores the address and passes it to 
//		functions or targets, where the pointer is unpacked and the value of the variable at that address is taken.
//
// Example: 

//#include <iostream>
//
//void passByPointer(int* ptr) {
//    std::cout << "Value before passByPointer: " << *ptr << std::endl;
//    (*ptr)++;
//}
//
//void passByReference(int& ref) {
//    std::cout << "Value before passByReference: " << ref << std::endl;
//    ref++;
//}
//
//int main() {
//    int num = 5;
//
//    // Pointer to num
//    int* ptr = &num;
//
//    // Reference to num
//    int& ref = num;
//
//    // Increment num using pointer
//    passByPointer(ptr);
//    std::cout << "Value after passByPointer: " << num << std::endl;
//
//    // Increment num using reference
//    passByReference(ref); // Increment num using reference
//    std::cout << "Value after passByReference: " << num << std::endl;
//
//    return 0;
//}
