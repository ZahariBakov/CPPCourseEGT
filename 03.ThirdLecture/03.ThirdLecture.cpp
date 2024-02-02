#include <iostream>

//int main() {
//    // logical AND
////      a true    false     true     false    age > 30
////      b true    true      false    false    exp > 5
////
//// result true    false     false     false
//
//// Is the number divisible by 5 and 7.
//    int number;
//
//    std::cout << "enter number: ";
//    std::cin >> number;
//
//    //if (number > 0) {
//    //    if (number % 5 == 0 && number % 7 == 0) {
//    //    // if(number > 0 && number % 5 == 0 && number % 7 == 0)
//    //        std::cout << "Number " << number << " is divisible." << std::endl;
//    //    }
//    //    else {
//    //        std::cout << "Number is not divisible." << std::endl;
//    //    }
//    //}
//    //else {
//    //    std::cout << number << " is a negative number" << std::endl;
//    //}
//
//    if (number > 0 || number % 5 == 0 && number % 7 == 0) {
//        std::cout << "Number " << number << " is divisible." << std::endl;
//    }
//    else {
//        std::cout << "Number is not divisible." << std::endl;
//    }    
//
//    return 0;
//}

//
//int main() {
//    for (int i = 1; i <= 100; ++i) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
//
//    int i = 3;
//
//    int a = i++; // a = 3, i = 4
//    std::cout << a << "<->" << i << std::endl;
//
//    int b = ++a; // b = 4, a = 4
//    std::cout << b << "<->" << i << std::endl;
//
//    return 0;
//}

//
//int main() {
//    int g = 0;
//    int j = 8888;
//
//    for (int k = 0; g < 100; k = k + 5) {
//        std::cout << "K is " << k << " ";
//        g++;
//        int j = k + 3;
//
//        std::cout << "J is " << j << " ";
//    }
//    std::cout << std::endl;
//
//    int k = 23;
//
//    std::cout << "K is: " << k << std::endl;
//    std::cout << "J is: " << j << std::endl;
//
//    return 0;
//}

//
//int main() {
//    int sum = 0;
//    long long prod = 1;
//
//    for (int i = 1; i < 1000; ++i) {
//        if (i % 5 == 0 && i % 7 == 0) {
//            if (i == 280) {
//                std::cout << "Skip 280 ";
//                continue;
//            }
//
//            if (i == 630) {
//                std::cout << "Break 630 ";
//                break;
//            }
//
//            std::cout << i << " ";
//            sum += i;
//            prod *= i;
//        }
//    }
//    std::cout << std::endl;
//
//    std::cout << "Sum of numbers is: " << sum << std::endl;
//    std::cout << "Multiplication is: " << prod << std::endl;
//
//    return 0;
//}

//
//int main() {
//    int sum = 0;
//
//    for (int i = 0; i <= 1000; ++i) {
//        sum += i;
//    }
//
//    std::cout << "Sum is " << sum << std::endl;
//
//    return 0;
//}

// 01. Сумата на нечетните числа от 1 до 100 които не се делят на 7.
//int main() {
//    int sum = 0;
//
//    for (int i = 0; i <= 100; ++i) {
//        if (i % 2 != 0 && i % 7 != 0) {
//            sum += i;
//        }
//    }
//
//    std::cout << "Sum is " << sum << std::endl;
//
//    return 0;
//}

// 01.1 Сумата на нечетните числа от 1 до 100 които се делят на 7.
//int main() {
//    int sum = 0;
//
//    for (int i = 0; i <= 100; ++i) {
//        if (i % 2 != 0 && i % 7 == 0) {
//            sum += i;
//        }
//    }
//
//    std::cout << "Sum is " << sum << std::endl;
//
//    return 0;
//}


// 02.Намерете сумата на цифрите на всяко число от 100 до 999.
//int main() {
//    int sum = 0;
//    int first = 0;
//    int second = 0;
//    int third = 0;
//
//    for (int i = 100; i < 1000; ++i) {
//        first = i;
//        third = first % 10;
//        first /= 10;
//
//        second = first % 10;
//        first /= 10;
//
//        sum = first + second + third;
//        std::cout << sum << std::endl;
//    }
//
//    return 0;
//}

// 2 а) да се пропуснат суми които завършват на 3
int main() {
    int sum = 0;
    int first = 0;
    int second = 0;
    int third = 0;

    for (int i = 100; i < 1000; ++i) {
        first = i;
        third = first % 10;
        first /= 10;

        second = first % 10;
        first /= 10;

        sum = first + second + third;

        if (sum == 3) {
            continue;
        }

        std::cout << sum << std::endl;
    }

    return 0;
}
