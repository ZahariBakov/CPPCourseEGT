#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

#include <vector>
#include <iomanip>

int main() {

    Shape* shape1 = new Shape(12.5);
    Shape* shape2 = new Circle(7.3);
    Shape* shape3 = new Rectangle(10.5, 15.8);

    //shape1->draw();
    //shape2->draw();
    //shape3->draw();

    std::vector<Shape*> shapesVec{ shape1, shape2 };
    shapesVec.push_back(shape3);

    for (auto shape : shapesVec) {
        shape->draw();
        Circle* circleShape = dynamic_cast<Circle*>(shape);
        Rectangle* rectangleshape = dynamic_cast<Rectangle*>(shape);

        if (circleShape) {
            std::cout << "Circle area is: " << std::fixed << std::setprecision(2) << shape->area() << "\n";
            std::cout << "Circle perimeter is: " << std::fixed << std::setprecision(2) << shape->perimeter() << std::endl;
        }
        else if (rectangleshape) {
            std::cout << "Rectangle area is: " << std::fixed << std::setprecision(2) << shape->area() << "\n";
            std::cout << "Rectangle perimeter is: " << std::fixed << std::setprecision(2) << shape->perimeter() << std::endl;
        }
    }

    return 0;
}