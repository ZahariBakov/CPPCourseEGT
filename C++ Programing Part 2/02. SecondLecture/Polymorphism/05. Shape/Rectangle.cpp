#include "Rectangle.h"

Rectangle::Rectangle(int a, int b) : TwoDShape(a), b(b) {}

double Rectangle::getArea() {
	double area = this->getA() * this->getB();

	std::cout << "In Rectangle area is " << area << std::endl;

	return area;
}

int Rectangle::getB() {
	return this->b;
}

void Rectangle::setB(int) {
	this->b = b;
}

void Rectangle::position() {
	std::cout << "Position in Rectangle." << std::endl;
}

bool Rectangle::fill() {
	char answer;
	std::cout << "Do you want to fill the rectangle? y/n ";
	std::cin >> answer;

	if (answer == 'Y' || answer == 'y') {
		std::cout << "Rectangle is fill." << std::endl;
		return true;
	}

	std::cout << "Rectangle is not fill." << std::endl;
	return false;
}

void Rectangle::draw() {
	this->fill();
	std::cout << "Rectangle is drawing..." << std::endl;
}

void Rectangle::print() {
	std::cout << "In Rectangle print width is " << this->getB() << std::endl;
}

bool operator<(Rectangle r1, Rectangle r2) {
	return r1.getArea() < r2.getArea();
}

bool operator>(Rectangle r1, Rectangle r2) {
	return r1.getArea() > r2.getArea();
}

bool operator==(Rectangle r1, Rectangle r2) {
	return r1.getArea() == r2.getArea();
}
