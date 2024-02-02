#include "Author.h"

Author::Author(std::string firstName, std::string lastName, std::string nationality)  {
	setFirstName(firstName);
	setLastName(lastName);
	setNationality(nationality);
}

void Author::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void Author::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void Author::setNationality(std::string nationality) {
	this->_nationality = nationality;
}

std::string Author::getFirstName() {
	return this->_firstName;
}

std::string Author::getLastName() {
	return this->_lastName;
}

std::string Author::getNationality() {
	return this->_nationality;
}

void Author::print() {
	std::cout << "Author: " << this->getFirstName() << " " << this->getLastName()
		<< " " << this->getNationality() << ". " << std::endl;
}
