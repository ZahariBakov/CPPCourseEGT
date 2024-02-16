#pragma once

#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(const std::string& color, double width, double height);

	void draw() const;

	double area() const override;

private:
	double width;
	double height;
};
