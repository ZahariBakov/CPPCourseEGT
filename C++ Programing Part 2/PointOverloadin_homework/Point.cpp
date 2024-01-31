#include "Point.h"

Point::Point() {}

Point::Point(int x, int y) {
	setX(x);
	setY(y);
}

void Point::setX(int x) {
	while (x <= 0) {
		std::cout << "Invalid X.Enter a positive number: ";
		std::cin >> x;
	}

	this->_x = x;
}

void Point::setY(int y) {
	while (y <= 0) {
		std::cout << "Invalid Y.Enter a positive number: ";
		std::cin >> y;
	}

	this->_y = y;
}

int Point::getX() const {
	return this->_x;
}

int Point::getY() const {
	return this->_y;
}

void Point::printPoint() const {
	std::cout << "The coordinates of the point are: " << this->getX() << " and " << getY() << std::endl;
}

Point operator+(Point p1, Point p2) {
	int x = p1.getX() + p2.getX();
	int y = p1.getY() + p2.getY();
	return Point(x, y);
}

Point operator-(Point p1, Point p2) {
	int x = p1.getX() - p2.getX();
	int y = p1.getY() - p2.getY();
	return Point(x, y);
}

Point operator*(Point p1, Point p2) {
	int x = p1.getX() * p2.getX();
	int y = p1.getY() * p2.getY();
	return Point(x, y);
}

Point operator/(Point p1, Point p2) {
	int x = p1.getX() / p2.getX();
	int y = p1.getY() / p2.getY();
	return Point(x, y);
}
