#include "Square.h"

Square::Square(int a) : TwoDShape(a) {}

double Square::getArea() {
	double area = this->getA() * this->getA();
	std::cout << "In Square area is " << area << std::endl;

	return area;
}

void Square::position() {
	std::cout << "Position in Square." << std::endl;
}

bool Square::fill() {
	char answer;
	std::cout << "Do you want to fill the square? y/n ";
	std::cin >> answer;

	if (answer == 'Y' || answer == 'y') {
		std::cout << "Square is fill." << std::endl;
		return true;
	}

	std::cout << "Square is not fill." << std::endl;
	return false;
}

void Square::draw() {
	this->fill();
	std::cout << "Square is drawing..." << std::endl;
}

void Square::print() {
	std::cout << "In Square print h is " << std::endl;
}
