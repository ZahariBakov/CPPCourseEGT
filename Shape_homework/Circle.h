#pragma once

#include "Shape.h"

class Circle : public Shape {

public:

	Circle(double);

	void draw() override;
	double area() override;
	double perimeter() override;

private:

};
