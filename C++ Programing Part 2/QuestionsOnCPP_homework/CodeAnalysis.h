#pragma once

//Code Analysis :
//	Given a snippet of C++ code containing a for loop, explain what the loop does, including how many times it iterates and why.
//
//	Този код съдържа "for" цикъл.
//	Цикълът инициализира целочислена променлива "i" със стойност 0.
//	Продължава да се повтаря, докато условието "i < 5" е вярно.
//	След всяка итерация цикълът увеличава стойността на "i" с 1.
//	Тялото на цикъла отпечатва текущия номер на "i", започвайки от 1, така че отпечатваме "i + 1".
//	Цикълът се изпълнява 5 пъти, като "i" приема съответно стойностите 0, 1, 2, 3 и 4.
//	След петата итерация условието "i < 5" става невярно и цикълът спира.
//
//	This code contains a "for" loop.
//	The loop initialize int variable "i" with the value 0.
//	Loop keep repeating until the condition "i < 5" is true.
//	After each iteration, the loop increments the value of "i" by 1.
//	The loop body prints the current number of "i", starting at 1, because we print "i + 1".
//	The loop is executed 5 times, with "i" taking the values 0, 1, 2, 3, and 4.
//	After the fifth iteration, the condition "i < 5" becomes false and the loop stops.
// 
// Example:

//#include <iostream>
//
//int main() {
//    for (int i = 0; i < 5; i++) {
//        std::cout << "Iteration " << i + 1 << std::endl;
//    }
//
//    return 0;
//}
