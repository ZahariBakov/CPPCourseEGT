#pragma once

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal(string, string, double);

	void setName(string);
	void setBreed(string);
	void setAge(double);

	string getName();
	string getBreed();
	double getAge();

	void print();

private:
	string breed;
	string name;
	double age;
};

