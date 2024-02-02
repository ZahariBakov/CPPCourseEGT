#pragma once

#include <iostream>

class Shape {

public:

	Shape(double);

	void setFirstSide(double);

	double getfisrtSide() const;

	virtual void draw();
	virtual double area();
	virtual double perimeter();

private:

	double _firstSide;
};
