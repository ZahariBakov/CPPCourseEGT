#include "Animal.h"

// constructor
Animal::Animal(string breed, string name, double age) {
	setBreed(breed);
	setName(name);
	setAge(age);
}


// setters
void Animal::setName(string name) {
	while (name.length() < 3)
	{
		cout << "The name must contain at least 3 characters. \n";
		cout << "Enter correct name: ";
		getline(cin >> ws, name);
	}
	this->name = name;
}

void Animal::setBreed(string breed) {
	while (breed.length() < 3)
	{
		cout << "The breed must contain at least 3 characters. \n";
		cout << "Enter correct breed: ";
		getline(cin >> ws, breed);
	}
	this->breed = breed;
}

void Animal::setAge(double age) {
	while (age < 0) {
		cout << "Age must be positive number! \n"; 
		cout << "Enter correct age: ";
		cin >> age;
	}
	this->age = age;
}


// getters
string Animal::getName() {
	return this->name = name;
}

string Animal::getBreed() {
	return this->breed = breed;
}

double Animal::getAge() {
	return this->age = age;
}


// functions
void Animal::print() {
	cout << "Breed: " << getBreed() << ", Name: " << getName() << ", Age: " << getAge() << " ";
}
