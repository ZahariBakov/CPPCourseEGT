#pragma once

#include "Animal.h"

class Dog : public Animal {
public:
	Dog(string, string, double, string);

	void setBark(string);

	string getBark();

	void print();

private:
	string bark;
};
