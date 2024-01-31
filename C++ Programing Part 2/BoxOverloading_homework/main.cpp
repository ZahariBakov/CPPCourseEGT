#include "Box.h"

int main() {

    Box box1(50, 40, 50);
    Box box2(30, 40, 50);
    Box box3 = box1 + box2;
    Box box4 = box1 - box2;

    box1.printBox();
    box2.printBox();
    box3.printBox();
    box4.printBox();

    return 0;
}
