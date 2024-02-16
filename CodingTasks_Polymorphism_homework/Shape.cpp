#include "Shape.h"

Shape::Shape(const std::string& color) : color(color) {}

void Shape::draw() const {
	std::cout << "Drawing a " << this->color << " shapes" << std::endl;
}
