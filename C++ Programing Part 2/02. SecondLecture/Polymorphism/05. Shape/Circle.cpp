#include "Circle.h"

Circle::Circle(int a) : TwoDShape(a) {}

double Circle::getArea() {
	double area = this->getA() * this->getA() * 3.14;

	std::cout << "In Circle area is " << area << std::endl;

	return area;
}

void Circle::position() {
	std::cout << "Position in Circle." << std::endl;
}

bool Circle::fill() {
	char answer;
	std::cout << "Do you want to fill the circle? y/n ";
	std::cin >> answer;

	if (answer == 'Y' || answer == 'y') {
		std::cout << "Circle is fill." << std::endl;
		return true;
	}

	std::cout << "Circle is not fill." << std::endl;
	return false;
}

void Circle::draw() {
	this->fill();
	std::cout << "Circle is drawing..." << std::endl;
}

void Circle::print() {
	std::cout << "In Circle print" << std::endl;
}
