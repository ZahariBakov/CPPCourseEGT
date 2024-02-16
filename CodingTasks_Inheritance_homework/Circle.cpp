#include "Circle.h"

Circle::Circle(const std::string& color) : Shape(color) {}

void Circle::draw() {
	std::cout << "Drawing a " << this->color << " circle" << std::endl;
}
