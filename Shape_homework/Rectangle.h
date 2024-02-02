#pragma once

#include "Shape.h"

class Rectangle : public Shape {

public:

	Rectangle(double, double);

	void setSecondSide(double);

	double getSecondSide() const;

	void draw() override;
	double area() override;
	double perimeter() override;

private:
	double _secondSide;
};
