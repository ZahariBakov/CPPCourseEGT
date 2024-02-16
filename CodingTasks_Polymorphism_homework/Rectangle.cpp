#include "Rectangle.h"

Rectangle::Rectangle(const std::string& color, double width, double height) : Shape(color), width(width), height(height) {}

void Rectangle::draw() const {
	std::cout << "Drawing a " << this->color << " rectangle" << std::endl;
}

double Rectangle::area() const {
	return this->width * this->height;
}
