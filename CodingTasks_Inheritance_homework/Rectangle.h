#pragma once

#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(const std::string& color);

	void draw();
};
