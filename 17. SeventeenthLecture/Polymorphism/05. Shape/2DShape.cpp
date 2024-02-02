#include "2DShape.h"

TwoDShape::TwoDShape(int a) : Shape(a) {}

double TwoDShape::getArea() {
	std::cout << "In 2D getArea" << std::endl;

	return 0;
}

void TwoDShape::position() {
	std::cout << "Position in 2D shape." << std::endl;
}

bool TwoDShape::fill() {
	char answer;
	std::cout << "Do you want to fill the shape? y/n ";
	std::cin >> answer;

	if (answer == 'Y' || answer == 'y') {
		std::cout << "Shape is fill." << std::endl;
		return true;
	}

	std::cout << "Shape is not fill." << std::endl;
	return false;
}

void TwoDShape::draw() {
	this->fill();
	std::cout << "2D Shape is drawing..." << std::endl;
}

void TwoDShape::print() {
	std::cout << "In 2D print" << std::endl;
}
