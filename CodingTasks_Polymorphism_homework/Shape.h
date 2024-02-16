#pragma once

#include <iostream>

class Shape {
public:
	Shape(const std::string& color);

	void draw() const;

	virtual double area() const = 0;

	virtual ~Shape() {};

protected:
	std::string color;
};
