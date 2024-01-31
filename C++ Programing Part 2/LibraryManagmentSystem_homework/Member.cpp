#include "Member.h"

// create new Member
Member::Member(std::string name, int age, std::string id) {
	setName(name);
	setAge(age);
	setMemberID(id);
}

// Setters to set all member variables. 
// We don't have any set requirements for them, that's why I haven't written any.
void Member::setName(std::string name) {
	this->_name = name;
}

void Member::setAge(int age) {
	this->_age = age;
}

void Member::setMemberID(std::string id) {
	this->_memberID = id;
}

// Getters 
std::string Member::getName() const {
	return this->_name;
}

int Member::getAge() const {
	return this->_age;
}

std::string Member::getMemberID() const {
	return this->_memberID;
}

// Display function for member
void Member::display() const {
	std::cout << "name: " << this->getName() << ", age: " << this->getAge() << ", with member id: " 
		<< this->getMemberID() << std::endl;
}

// Borrow function 
void Member::borrowBook(Book* book) {
	std::cout << "Member ";
	this->display();
	std::cout << "Borrow book: ";
	book->display();
	std::cout << std::endl;
}
