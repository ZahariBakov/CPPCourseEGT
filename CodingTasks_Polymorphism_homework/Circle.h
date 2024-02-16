#pragma once

#include "Shape.h"

class Circle : public Shape {
public:
	Circle(const std::string& color, double radius);

	void draw() const;

	double area() const override;

private:
	double radius;
};
