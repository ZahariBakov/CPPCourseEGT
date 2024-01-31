#include "Dog.h"

Dog::Dog(string breed, string name, double age, string bark) : Animal(breed, name, age) {
	setBark(bark);
}

void Dog::setBark(string bark) {
	this->bark = bark;
}

string Dog::getBark() {
	return this->bark;
}

void Dog::print() {
	Animal::print();

	cout << "- " << this->bark << endl;
}
