#include "Cat.h"

Cat::Cat(string breed, string name, double age, string meow) : Animal(breed, name, age) {
	setMeow(meow);
}

void Cat::setMeow(string meow) {
	this->meow = meow;
}

string Cat::getMeow() {
	return this->meow;
}

void Cat::print() {
	Animal::print();

	cout << "- " << this->meow << endl;
}
