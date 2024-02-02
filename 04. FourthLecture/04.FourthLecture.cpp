#include <iostream>

// 01.Find all numbers from 1 to "num" that are divisible by "a" and "b".
//int main() {
//    using namespace std;
//
//    int num, a, b; 
//
//    cout << "Enter numbers: ";
//    cin >> num >> a >> b;
//
//    for (int i = 1; i <= num; ++i) {
//        if (i % a == 0 && i % b == 0) {
//            cout << i << " ";
//        }
//    }
//    
//    cout << endl;
//
//    // output: 21 42 63 84
//    // input 100 7 3
//
//    //
//    //const int M = 0;
//
//    //M += 1;
//
//    //cout << M << endl;
//    return 0;
//}

// 02.Different between ++a and b++
//int main() {
//
//    int a;
//    int b;
//
//    a = 5;
//    b = 5;
//
//    std::cout << a++ << std::endl;
//    std::cout << ++b << std::endl;
//
//    return 0;
//}

// 03.Find all prime number
//int main() {
//    int n;
//    std::cin >> n;
//
//    int counter = 0;
//    for (int i = 1; i <= n; ++i) {
//        for (int k = 2; k < i; ++k) {
//            if (i % k == 0) {
//                ++counter;
//            }
//        }
//
//        if (counter == 0) {
//            std::cout << i << " ";
//        }
//        counter = 0;
//    }
//
//    return 0;
//}

// 04.k^3 < n; max k.
//int main() {
//    // input 100
//    // output 4
//    int n;
//    std::cin >> n;
//
//    int stepen = 3;
//    int temp = 1;
//    int maxK = 1;
//
//    for (int i = 1; i < n; ++i) {
//        for (int k = 0; k < stepen; ++k) {
//            temp *= i;
//        }
//
//        if (temp < n && temp  > maxK) {
//            maxK = i;
//            temp = 1;
//        }
//
//        if (temp >= n) {
//            break;
//        }
//    }
//
//    std::cout << maxK << std::endl;
//    return 0;
//}

// 05.From two numbers, find the sum of all the numbers between them.
//int main() {
//    int a, b;
//    std::cin >> a >> b;
//    int sum = 0;
//
//    for (int i = a; i < b; ++i) {
//        sum += i;
//    }
//
//    std::cout << sum << std::endl;
//    return 0;
//}

// 06.Printing triangle
//int main() {
//    int n;
//    std::cin >> n;
//
//    for (int i = 0; i <= n; ++i) {
//        for (int k = 0; k < i; ++k) {
//            std::cout << "*";
//        }
//        std::cout << std::endl;
//    }
// 
//    return 0;
//}

// 07.Printing square
//int main() {
//    int n;
//    std::cin >> n;
//
//    for (int i = 0; i <= n; ++i) {
//        for (int k = 0; k < n; ++k) {
//            std::cout << "*";
//        }
//        std::cout << std::endl;
//    }
//
//    return 0;
//}

// 08.Pringting reverse triangle
//int main() {
//    int n;
//    std::cin >> n;
//
//    for (int i = 0; i <= n; ++i) {
//        for (int k = n; k > i; --k) {
//            std::cout << "*";
//        }
//        std::cout << std::endl;
//    }
//
//    return 0;
//}

// 09.All numbers from 1 to N that i ^ i < N.
//int main() {
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i) {
//        if (i * i < n) {
//            std::cout << i * i << " ";
//        }
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

// Homework:

// 01.All numbers from 1 to num that i ^ pow < num.

//int main() {
//    int num;
//    int pow;
//    std::cout << "Enter number: ";
//    std::cin >> num;
//    
//    std::cout << "Enter pow: ";
//    std::cin >> pow;
//
//    int currPowNum = 1;
//
//    for (int i = 1; i < num; ++i) {
//        for (int k = 0; k < pow; ++k) {
//            currPowNum *= i;
//        }
//
//        if (currPowNum < num) {
//            std::cout << "Number: " << i << " on the power of " << pow << " equals: " << currPowNum << std::endl;
//            currPowNum = 1;
//        }
//        else {
//            break;
//        }
//    }
//
//return 0;
//}

// 02.Mirror triangle pinting
 //    *
 //   **
 //  ***
 // ****
 //*****

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    for (int i = 0; i <= num; ++i) {
        for (int k = num; k > i; --k) {
            std::cout << ' ';
        }

        for (int j = 0; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}
