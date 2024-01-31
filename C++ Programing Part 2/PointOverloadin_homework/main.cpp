#include "Point.h"

int main() {

    Point p1(50, 40);
    Point p2(5, 10);
    Point p3 = p1 + p2;
    Point p4 = p1 - p2;
    Point p5 = p2 * p4;
    Point p6 = p1 / p4;

    p1.printPoint();
    p2.printPoint();
    p3.printPoint();
    p4.printPoint();
    p5.printPoint();
    p6.printPoint();

    return 0;
}
