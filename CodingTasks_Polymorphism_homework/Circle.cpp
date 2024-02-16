#include "Circle.h"

#define _USE_MATH_DEFINES

#include <math.h>

Circle::Circle(const std::string& color, double radius) : Shape(color), radius(radius) {}

void Circle::draw() const {
	std::cout << "Drawing a " << this->color << " circle" << std::endl;
}

double Circle::area() const {
	return M_PI * this->radius * this->radius;
}
