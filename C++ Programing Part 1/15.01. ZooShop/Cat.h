#pragma once

#include "Animal.h"

class Cat : public Animal {
public:
	Cat(string, string, double, string);

	void setMeow(string);

	string getMeow();

	void print();

private:
	string meow;
};
