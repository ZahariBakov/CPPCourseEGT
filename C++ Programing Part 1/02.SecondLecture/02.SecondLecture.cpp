//#include <iostream>
//
//int main() {
//    // int side;
//    // std::cin >> side;
//
//    // perimeter
//    // std::cout << 4 * side << std::endl;
//
//    // square
//    // std::cout << side * side << std::endl;
//
//    // int a;
//    // std::cin >> a;
//
//    // std::cout << a % 10 << std::endl;
//    // std::cout << (a / 10) % 10 << std::endl;
//    // std::cout << (a / 100) % 10 << std::endl;
//
//     // printing number from last to first in new line
//    /*while (a > 0) {
//        std::cout << a % 10 << std::endl;
//        a = a / 10;
//    }*/
//
//    // printing revesre number
//    /*while (a > 0) {
//        std::cout << a % 10;
//        a = a / 10;
//    }*/
//
//    /*int a, b, c;
//    std::cout << "a: ";
//    std::cin >> a;
//
//    std::cout << "b: ";
//    std::cin >> b;
//
//    std::cout << "c: ";
//    std::cin >> c;
//
//    if (a%2 == 0 && b%2 == 0 && c%2 == 0) {
//        std::cout << "a, b, c is even" << std::endl;
//    }
//    else {
//        std::cout << "a, b, c have odd" << std::endl;
//    }*/
//
//    /*int n;
//    std::cin >> n;
//
//    int secondPerMinutes = 60;
//    int minutesPerHour = 60;
//    int secondPerHour = secondPerMinutes * minutesPerHour;
//
//    std::cout << "Hours " << n / secondPerHour 
//        << ", and seconds " << n % secondPerHour << std::endl;*/
//
//    /*int a;
//    std::cin >> a;
//
//    if (a > 0) {
//        std::cout << a * a << std::endl;
//    }
//    else {
//        std::cout << a << std::endl;
//    }*/
//
//    /*int a, b, c;
//
//    std::cout << "a: ";
//    std::cin >> a;
//
//    std::cout << "b: ";
//    std::cin >> b;
//
//    std::cout << "c: ";
//    std::cin >> c;
//
//    if (a < b) {
//        if (a < c) {
//            std::cout << a << std::endl;
//        }
//        else {
//            std::cout << c << std::endl;
//        }
//    }
//    else {
//        if (b < c) {
//            std::cout << b << std::endl;
//        }
//        else {
//            std::cout << c << std::endl;
//        }
//    }*/
//
//    // Day of the week
//    /*int a;
//    std::cin >> a;
//
//    std::string day;
//
//    switch (a)
//    {case 1:
//        day = "Monday";
//        break;
//    case 2:
//        day = "Tuesday";
//        break;
//    case 3:
//        day = "Wednesday";
//        break;
//    case 4:
//        day = "Thursday";
//        break;
//    case 5:
//        day = "Friday";
//        break;
//    case 6:
//        day = "Saturday";
//        break;
//    case 7:
//        day = "Sunday";
//        break;
//    default:
//        day = "It's not a day of the week";
//        break;
//    }
//
//    std::cout << day << std::endl;*/
//
//    /*char a[15] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'g', 
//        'k', 'l', 'm', 'n', 'o' };
//
//    int number;
//    std::cin >> number;
//
//    if (number <= 0 && number < 16) {
//        std::cout << a[number - 1] << std::endl;
//    }
//    else {
//        std::cout << "Is not in first 15 letters in alphabets." << std::endl;
//    }*/
//
//    /*int a[3] = { 'a', 'b', 'c' };
//    std::cout << a[0] << std::endl;
//    std::cout << a[1] << std::endl;
//    std::cout << a[2] << std::endl;*/
//
//    // Fahrenheit to Celsius
//    /*double fahrenheit;
//    std::cin >> fahrenheit;
//
//    double celsius = (fahrenheit - 32) * (5.0 / 9);
//
//    std::cout << celsius << std::endl;*/
// 
//    // switch 
//    /*int a, b;
//    std::cin >> a;
//    std::cin >> b;
//
//    std::cout << "a: " << a << " b: " << b << std::endl;
//
//    int temp = a; 
//    a = b;
//    b = temp;
//
//    std::cout << "a: " << a << " b: " << b << std::endl;*/
//
//    // Celsius to Fahrenheit.
//    /*double celsius;
//    std::cout << "Enter degree in Celsius: "; 
//    std::cin >> celsius;
//
//    double fahrenheit = (celsius * (9.0 / 5)) + 32;
//    std::cout << "Degree in Fahrenheit is: " << fahrenheit << std::endl;*/
//
//    return 0;
//}


// Print the numbers one by one
#include <iostream>

int main() {
    int number = 0;
    std::cout << "Enter number: ";
    std::cin >> number;

    int temp = 0;
    int currNum = 0;

    int numberCount = 0;
    int tempCount = 0;

    while (number > 0) {
        temp *= 10;
        currNum = number % 10;

        if (currNum != 0) {
            temp += currNum;
        }
        
        number /= 10;
        numberCount++;
    }

    while (temp > 0) {
        std::cout << (temp % 10) << std::endl;
        temp /= 10;
        tempCount++;
    }

    if (tempCount < numberCount) {
        std::cout << 0 << std::endl;
    }

    return 0;
}
