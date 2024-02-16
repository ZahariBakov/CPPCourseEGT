#include "Rectangle.h"

Rectangle::Rectangle(const std::string& color) : Shape(color) {}

void Rectangle::draw() {
	std::cout << "Drawing a " << this->color << " rectangle" << std::endl;
}
