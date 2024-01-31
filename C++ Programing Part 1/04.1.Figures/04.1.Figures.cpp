#include <iostream>

// 01.Pyramid
//*
//***
//*****
//*******
//*********

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//    int star = 1;
//
//    for (int i = 0; i <= number / 2; ++i) {
//
//        for (int j = number / 2; j > i; --j) {
//            std::cout << " ";
//        }
//
//        for (int k = 0; k < star; ++k) {
//            std::cout << "*";
//        }
//        star += 2;
//        std::cout << std::endl;
//    }
//
//    return 0;
//}


// 02.Hourglass
//*********
//*******
//*****
//***
//*

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//    int star = number;
//
//    for (int i = 0; i <= number / 2; ++i) {
//        for (int j = 0; j < i; ++j) {
//            std::cout << " ";
//        }
//
//        for (int k = 0; k < star; ++k) {
//            std::cout << "*";
//        }
//
//        std::cout << std::endl;
//        star -= 2;
//    }
//
//    return 0;
//}


// 03.Diamond
//*
//***
//*****
//*******
//*********
//*******
//*****
//***
//*

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//    int star = 1;
//
//    for (int i = 0; i <= number / 2; ++i) {
//
//        for (int j = number / 2; j > i; --j) {
//            std::cout << " ";
//        }
//
//        for (int k = 0; k < star; ++k) {
//            std::cout << "*";
//        }
//        star += 2;
//        std::cout << std::endl;
//    }
//
//    star -= 4;
//
//    for (int i = 1; i <= number / 2; ++i) {
//        for (int k = 0; k < i; ++k) {
//            std::cout << " ";
//        }
//
//        for (int j = 0; j < star; ++j) {
//            std::cout << "*";
//        }
//
//        std::cout << std::endl;
//        star -= 2;
//    }
//
//    return 0;
//}


// 04.Cross Pattern
//  *
//  *
//*****
//  *
//  *

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//
//    for (int i = 0; i < number / 2; ++i) {
//        for (int j = 0; j < number / 2; ++j) {
//            std::cout << " ";
//        }
//
//        std::cout << "*" << std::endl;
//    }
//
//    for (int k = 0; k < number; ++k) {
//        std::cout << "*";
//    }
//
//    std::cout << std::endl;
//
//    for (int i = 0; i < number / 2; ++i) {
//        for (int j = 0; j < number / 2; ++j) {
//            std::cout << " ";
//        }
//
//        std::cout << "*" << std::endl;
//    }
//
//    return 0;
//}


// 05.X Pattern
//*   *
// * *
//  *
// * *
//*   *

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//    int freeSpaces = number - 2;
//
//    for (int i = 0; i < number / 2; ++i) {
//        for (int k = 0; k < i; ++k) {
//            std::cout << " ";
//        }
//                
//        std::cout << "*";
//
//        for (int j = 0; j < freeSpaces; ++j) {
//            std::cout << " ";
//        }
//
//        std::cout << "*";
//
//        std::cout << std::endl;
//        freeSpaces -= 2;
//    }
//
//    for (int i = 0; i < number / 2; ++i) {
//        std::cout << " ";
//    }
//
//    std::cout << "*" << std::endl;
//
//    freeSpaces = 1;
//
//    for (int i = 1; i <= number / 2; ++i) {
//        for (int k = number / 2; k > i; --k) {
//            std::cout << " ";
//        }
//
//        std::cout << "*";
//
//        for (int j = 0; j < freeSpaces; ++j) {
//            std::cout << " ";
//        }
//
//        std::cout << "*";
//    
//        std::cout << std::endl;
//        freeSpaces += 2;
//    }    
//
//    return 0;
//}


// 06.Checkerboard
//* * * * *
// * * * * *
//* * * * *
// * * * * *
//* * * * *

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//
//    for (int row = 1; row <= number; ++row) {
//
//        if (row & 1 == 1) {
//            for (int j = 0; j < number; ++j) {
//                std::cout << "* ";
//            }
//        }
//        else {
//            for (int k = 0; k < number; ++k) {
//                std::cout << " *";
//            }
//        }
//
//        std::cout << std::endl;        
//    }
//
//    return 0;
//}


// 07.Number Pattern
//1
//22
//333
//4444
//55555

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//
//    for (int i = 1; i <= number; ++i) {
//        for (int j = 0; j < i; ++j) {
//            std::cout << i;
//        }
//        std::cout  << std::endl;
//    }
//
//    return 0;
//}


// 08.Spiral Pattern
//12345
//16  6
//15  7
//14  8
//13  9
//121110

int main() {
    int number;
    std::cout << "Enter number: ";
    std::cin >> number;
    int firstCol = number * 2 - 1;

    int secondRowLength = 0;
    int currNum = firstCol + 1;

    for (int x = 0; x < number; ++x) {

        if (currNum > 9) {
            secondRowLength += 2;
        }
        else {
            secondRowLength += 1;
        }

        if (secondRowLength >= number) {
            break;
        }

        currNum++;
    }

    int secondColNums = currNum + (number - 1);
    int freeSpaces;
    int lastNum = secondColNums;

    // Printing first row
    for (int i = 1; i <= number; ++i) {
        std::cout << i;
    }

    std::cout << std::endl;

    // Printing cols
    for (int j = number + 1; j <= firstCol; ++j) {
        std::cout << lastNum;

        if (lastNum > 9) {
            freeSpaces = number - 2;
        }
        else {
            freeSpaces = number - 1;
        }

        if (j > 9) {
            freeSpaces -= 2;
        }
        else {
            freeSpaces -= 1;
        }


        for (int k = 0; k < freeSpaces; ++k) {
            std::cout << " ";
        }

        std::cout << j << std::endl;
        lastNum--;
    }

    // Printng second row
    for (int y = currNum; y > firstCol; --y) {
        std::cout << y;
    }

    return 0;
}