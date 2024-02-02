#include "Circle.h"

Circle::Circle(double side) : Shape(side) {}

void Circle::draw() {
	std::cout << "\nCircle is drawing...\n";
	std::cout << "Calling from Circle: " << std::endl;
	Shape::draw();
}

double Circle::area() {

	double result = 3.14 * Shape::getfisrtSide() * Shape::getfisrtSide();

	return result;
}

double Circle::perimeter() {

	double result = 2 * 3.14 * Shape::getfisrtSide();

	return result;
}
