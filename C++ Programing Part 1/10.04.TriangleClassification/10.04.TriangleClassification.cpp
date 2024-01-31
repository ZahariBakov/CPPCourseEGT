#include <iostream>

class Triangle {
public:
    // constructor
    Triangle(double s1, double s2, double s3) 
    : side1(s1), side2(s2), side3(s3) {}

    // function
    void determineType() {
        if (side1 == side2 && side2 == side3) {
            std::cout << "Equilateral Triangle" << std::endl;
        }
        else if (side1 == side2 || side1 == side3 || side2 == side3) {
            std::cout << "Isosceles Triangle" << std::endl;
        }
        else {
            std::cout << "Scalene Triangle" << std::endl;
        }
    }

private:
    double side1;
    double side2;
    double side3;
};

int main() {
    double s1, s2, s3;
    std::cout << "Input the lengths of the three sides of the triangle:\n";
    std::cout << "Side1: ";
    std::cin >> s1;
    std::cout << "Side2: ";
    std::cin >> s2;
    std::cout << "Side3: ";
    std::cin >> s3;

    Triangle triangle(s1, s2, s3);

    // Determine the type of triangle
    triangle.determineType();

    return 0;
}
