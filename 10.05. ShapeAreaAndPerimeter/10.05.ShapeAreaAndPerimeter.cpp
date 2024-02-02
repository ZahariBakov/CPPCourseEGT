#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

const double pi = M_PI;

class Shape {
public:
    // Function
    double calculateArea() {};

    double calculatePerimeter() {};
};

class Circle : public Shape {
public:
    // Constructor
    Circle(double rad) : radius(rad) {}

    // Functions
    double calculateArea() const {
        return pi * pow(radius, 2);
    }

    double calculatePerimeter() const {
        return 2 * pi * radius;
    }

private: 
    double radius;
};

class Rectangle : public Shape {
public:
    // Constructor
    Rectangle(double len, double wid) 
        : length(len), width(wid) {}

    // Functions
    double calculateArea() const {
        return length * width;
    }

    double calculatePerimeter() const {
        return 2 * (length + width);
    }

private: 
    double length;
    double width;
};

class Triangle : public Shape {
public:
    // Constructor
    Triangle(double s1, double s2, double s3) 
        : side1(s1),  side2(s2), side3(s3) {}

    // Functions
    double calculateArea() const {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() const {
        return side1 + side2 + side3;
    }

private:
    double side1;
    double side2;
    double side3;
};

int main() {
    Circle circle(7.0);
    Rectangle rectangle(4.2, 8.0);
    Triangle triangle(4.0, 4.0, 3.2);

    std::cout << "Circle: " << "\n";
    std::cout << "Area: " << circle.calculateArea() << "\n";
    std::cout << "Perimeter: " << circle.calculatePerimeter() << "\n\n";

    std::cout << "Rectangle: " << "\n";
    std::cout << "Area: " << rectangle.calculateArea() << "\n";
    std::cout << "Perimeter: " << rectangle.calculatePerimeter() << "\n\n";

    std::cout << "Triangle: " << "\n";
    std::cout << "Area: " << triangle.calculateArea() << "\n";
    std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;

    return 0;
}
