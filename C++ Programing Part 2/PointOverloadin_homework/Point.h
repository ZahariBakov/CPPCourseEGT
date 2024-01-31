#pragma once

#include <iostream>

class Point {

	friend Point operator+(Point, Point);
	friend Point operator-(Point, Point);
	friend Point operator*(Point, Point);
	friend Point operator/(Point, Point);

public:

	Point();
	Point(int, int);

	void setX(int);
	void setY(int);

	int getX() const;
	int getY() const;

	void printPoint() const;

private:

	int _x;
	int _y;
};
