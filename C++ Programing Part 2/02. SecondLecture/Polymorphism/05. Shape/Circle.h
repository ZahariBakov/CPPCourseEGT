#pragma once

#include "2DShape.h"

class Circle : public TwoDShape {
public:
	Circle(int);

	double getArea();

	void position();
	bool fill();
	void draw();

	void print();

private:

};
