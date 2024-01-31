#pragma once

#include "Shape.h"

class TwoDShape : public Shape {

public:
	TwoDShape(int);

	double getArea();

	virtual void position();
	virtual bool fill();
	virtual void draw();
	
	void print();
};
