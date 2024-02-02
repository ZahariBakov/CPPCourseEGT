//#pragma once
//
//Concept Clarification :
//	Explain the difference between a while loop and do - while loop in C++.
//
//	Основната разлика между цикъла "while" и цикъла "do-while" в
//	C++ се състои в това кога се проверява условието на цикъла :
//
//	В "while" цикъла условието се оценява преди да се изпълни тялото на цикъла.
//	Ако условието първоначално е невярно, тялото на цикъла изобщо няма да се изпълни.
//	Ако условието е вярно, тялото на цикъла ще се изпълни и условието ще бъде преоценявано преди всяка итерация.
//
//	В "do-while" цикъла условието се оценява, след като тялото на цикъла е било изпълнено поне веднъж.
//	Това означава, че тялото на цикъла е гарантирано, че ще се изпълни поне веднъж, независимо дали условието е вярно или невярно първоначално.
//	След първата итерация условието ще се оценява преди всяка следваща итерация.
//	След първата итерация условието ще се оценява преди всяка следваща итерация.
//
//	The main difference between the "while" loop and the "do-while" loop in C++ is when the condition of the loop is checked :
//
//	In "while" loop, condition is check before the loop body is executed.
//	If the condition is initially false, loop body will not execute.
//	If the condition is true, the loop body will execute and the condition will be check before each iteration.
//
//	In a "do-while" loop, the condition is check after the body of the loop has been executed at least once.
//	This means that the body of the loop is guaranteed to execute at least once, regardless of whether the condition is true or false at first time.
//	After the first iteration, the condition will be check before each next iteration.
//
//	Example:

//#include <iostream>
//
//int main() {
//    int count = 0;
//
//    // While loop
//    std::cout << "In while loop: " << std::endl;
//    while (count < 5) {
//        std::cout << "Count: " << count << std::endl;
//        count++; // Increment count
//    }
//
//    count = 0;
//
//    // Do-while loop
//    std::cout << "\nIn do-while loop: " << std::endl;
//    do {
//        std::cout << "Count: " << count << std::endl;
//        count++; // Increment count
//    } while (count < 5);
//
//    return 0;
//}

