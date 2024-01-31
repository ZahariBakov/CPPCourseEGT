#include "Shape.h"

Shape::Shape(int side) : a(side) {}

double Shape::getArea() {
	std::cout << "In shape the area is" << std::endl;

	return 0;
}

int Shape::getA() {
	return this->a;
}

void Shape::setA(int side) {
	this->a = side;
}

void Shape::print() {
	std::cout << "In shape the side is " << this->a << std::endl;
}
