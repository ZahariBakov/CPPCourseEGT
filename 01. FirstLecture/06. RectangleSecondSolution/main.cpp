#include "Point.h"
#include "Rectangle.h"

int main() {
    Point p1(5, 5);
    std::cout << p1.getX() << " ";
    std::cout << p1.getY() << std::endl;

    Point p2(15, 5);
    std::cout << p2.getX() << " ";
    std::cout << p2.getY() << std::endl;

    Point p3(5, 15);
    std::cout << p3.getX() << " ";
    std::cout << p3.getY() << std::endl;

    Point p4(15, 15);
    std::cout << p4.getX() << " ";
    std::cout << p4.getY() << std::endl;

    Rectangle r1(p1, p2, p3, p4);
    if (r1.isRectangle()) {
        std::cout << "This is Rectangle." << std::endl;
    }
    
    if (r1.isSquare()) {
        std::cout << "This is Square." << std::endl;
    }

    return 0;
}
