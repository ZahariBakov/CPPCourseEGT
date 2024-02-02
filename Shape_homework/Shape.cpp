#include "Shape.h"

Shape::Shape(double side) {
	setFirstSide(side);
}

void Shape::setFirstSide(double side) {
	while (side < 0) {
		std::cout << "The side must be a poditive number. ";
		std::cin >> side;
	}

	this->_firstSide = side;
}

double Shape::getfisrtSide() const {
	return this->_firstSide;
}

void Shape::draw() {
	std::cout << "Shape is drawing..." << std::endl;
}

double Shape::area() {
	return 0.0;
}

double Shape::perimeter() {

	return 0.0;
}
