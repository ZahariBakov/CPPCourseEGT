#pragma once

#include <iostream>

class Shape {
public:
	Shape(int);

	virtual double getArea();
	int getA();

	void setA(int);

	virtual void print();

private:
	int a;
};
