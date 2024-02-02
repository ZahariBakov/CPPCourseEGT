#include "Author.h"

Author::Author(std::string fName, std::string lName, std::string nationality) {
	setFirstName(fName);
	setLastName(lName);
	setNationality(nationality);
}

void Author::setFirstName(std::string fName) {
	this->firstName = fName;
}

void Author::setLastName(std::string lName) {
	this->lastName = lName;
}

void Author::setNationality(std::string n) {
	this->nationality = n;
}

std::string Author::getFirstName() {
	return this->firstName;
}

std::string Author::getLastName() {
	return this->lastName;
}

std::string Author::getNationality() {
	return this->nationality;
}

void Author::print() const {
	std::cout << this->firstName << " " << this->lastName << " " << this->nationality << std::endl;
}
