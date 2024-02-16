#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

void printArea(const Shape* shape) {
    std::cout << "Area: " << shape->area() << std::endl;
}

int main() {
    Circle circle("red", 5.0);
    Rectangle rectangle("yellow", 4.0, 6.0);

    circle.draw();
    rectangle.draw();

    printArea(&circle);
    printArea(&rectangle);

    return 0;
}
