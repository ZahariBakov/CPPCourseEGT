#pragma once

#include <iostream>

class Shape {
public:
	Shape(const std::string& color);

	void draw();

protected:
	std::string color;
};
