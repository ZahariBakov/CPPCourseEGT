#include <iostream>

class Rectangle {
public:
    // Constructor
    Rectangle(double wid, double len) 
        : width(wid), length(len) {}

    // getters
    double getWidth() {
        return width;
    }

    double getLength() {
        return length;
    }

    // setters
    double setWitdh(double width) {
        this->width = width;
    }

    double setLength(double length) {
        return this->length = length;
    }

    // function
    double calculateArea() {
        return width * length;
    }

    double calculatePerimeter() {
        return 2 * (width + length);
    }

private:
    double width = 0;
    double length = 0;
};

int main() {
    double length, width;
    std::cout << "Input the length of the rectangler: ";
    std::cin >> length;
    std::cout << "Input the width of the rectangle: ";
    std::cin >> width;

    // Create a rectangle object
    Rectangle rectangle(length, width);

    // Calculate and display the area
    double area = rectangle.calculateArea();
    std::cout << "\nArea: " << area << std::endl;

    // Calculate and display the perimeter
    double perimeter = rectangle.calculatePerimeter();
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}
