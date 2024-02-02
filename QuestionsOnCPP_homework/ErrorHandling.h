#pragma once

//Error Handling :
//	Describe how exceptions are used in C++ for error handling, with an
//	example of a try - catch block.
//
//	При изпълнение на код могат да възникнат различни грешки.Като грешки в кода, такива направени от програмиста, 
//	грешно въвеждане или други непредвидени неща.
//	Когато възникне грешка, C++ спира и генерира съобщение за грешка.
//
//	"try", "throw" and "catch"
//	"try" ни позволява да дефинирате блок от код, който очакваме, че може да хвърли грешка.
//	"throw" хваща грешката, ако когато бъде открита такава.
//	"catch" изпълняваме друг блок от код ако има грешка в "try".
//
//	When running code can make various errors.Like as code errors, made by programmer, wrong input or other unforeseen things.
//	When an error occurs, C++ stops and generates an error message.
//
//	"try", "throw" and "catch"
//	"try" allows us to define a block of code that we expect might throw an error.
//	"throw" catches the error if one is encountered.
//	"catch" we execute another block of code if there is an error in "try".
// 
// Example:

//#include <iostream>
//
//int main() {
//
//    try {
//        int num = -1;
//
//        if (num > 0) {
//            std::cout << "Number is positive." << std::endl;
//        }
//        else {
//            throw (num);
//        }
//    }
//
//    catch (int num) {
//        std::cout << "Number must be positive! You number is: " << num << std::endl;
//    }
//
//    return 0;
//}
