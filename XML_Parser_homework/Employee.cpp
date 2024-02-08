#include "Employee.h"

Employee::Employee(std::string name, std::string type, int age) {
	setName(name);
	setType(type);
	setAge(age);
}

Employee::~Employee() {}

void Employee::setName(std::string name) {
	this->_name = name;
}

void Employee::setType(std::string type) {
	this->_type = type;
}

void Employee::setAge(int age) {
	this->_age = age;
}

void Employee::displayInfo() const {
	std::cout << "Name: " << getName() << " Type: " << getType() << " Age: " << getAge() << std::endl;
}

std::string Employee::getName() const {
	return this->_name;
}

std::string Employee::getType() const {
	return this->_type;
}

int Employee::getAge() const {
	return this->_age;
}
