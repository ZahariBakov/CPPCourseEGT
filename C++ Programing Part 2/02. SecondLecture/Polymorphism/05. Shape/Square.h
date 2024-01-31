#pragma once

#include "2DShape.h"

class Square : public TwoDShape {
public:
	Square(int);

	double getArea();

	void position();
	bool fill();
	void draw();

	void print();

private:

};
