#pragma once

#include "Point.h"

class Rectangle {
public:
	Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

	const Point& getP1() const;
	const Point& getP2() const;
	const Point& getP3() const;
	const Point& getP4() const;

	void setP1(const Point& p1);
	void setP2(const Point& p1);
	void setP3(const Point& p1);
	void setP4(const Point& p1);

	bool isRectangle();
	bool isSquare();

private:
	Point p1;
	Point p2;
	Point p3;
	Point p4;

	int calculateDistance(int, int);
};
