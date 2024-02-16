#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

int main() {
    Shape shape("blue");
    Circle circle("red");
    Rectangle rectangle("yellow");

    shape.draw();
    circle.draw();
    rectangle.draw();

    return 0;
}
