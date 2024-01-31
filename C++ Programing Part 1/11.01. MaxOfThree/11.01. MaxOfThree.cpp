#include <iostream>

double readNumber() {
    double number;

    std::cin >> number;

    return number;
}

double maxNumber(double a, double b, double c) {
    double max;

    if (a >= b && a >= c) {
        max = a;
    }
    else if (b > a && b >= c) {
        max = b;
    }
    else {
        max = c;
    }

    return max;
}

void printSolution(double num, double a, double b, double c) {
    std::cout << "The biggest number from " << a << ", " << b << " and " << c << " is " << num << std::endl;
}

int main() {
    double a, b, c;
    std::cout << "Enter a three numbers: ";
    a = readNumber();
    b = readNumber();
    c = readNumber();

    double max = maxNumber(a, b, c);

    printSolution(max, a, b, c);

    return 0;
}
