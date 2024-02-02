#include "3DShape.h"

ThreeDShape::ThreeDShape(int a, int h) : Shape(a), h(h) {}

double ThreeDShape::getArea() {
	std::cout << "In 3D getArea." << std::endl;

	return 0;
}

int ThreeDShape::getVolume() {
	std::cout << "In 3D getVolume." << std::endl;

	return 0;
}

int ThreeDShape::getH() {
	return this->h;
}

void ThreeDShape::setH(int) {
	this->h = h;
}

void ThreeDShape::print() {
	std::cout << "In 3D print h is " << this->getH() << std::endl;
}
