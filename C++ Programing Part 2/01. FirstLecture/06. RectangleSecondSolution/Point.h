#pragma once

#include <iostream>

class Point {
public:
	Point(int x, int y);

	int getX() const;
	int getY() const;

	void setX(int x);
	void setY(int y);
	
private:
	int x;
	int y;
};
