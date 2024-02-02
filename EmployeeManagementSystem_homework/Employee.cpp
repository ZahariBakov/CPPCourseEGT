#include "Employee.h"

Employee::Employee(std::string name, int id, std::string pos) {
	setName(name);
	setEmployeeID(id);
	setPosition(pos);
}

// Setters to set all Employee variables. 
// We don't have any set requirements for them, that's why I haven't written any.
void Employee::setName(std::string name) {
	this->_name = name;
}

void Employee::setEmployeeID(int id) {
	this->_employeeID = id;
}

void Employee::setPosition(std::string pos) {
	this->_position = pos;
}

// getters
std::string Employee::getName() const {
	return this->_name;
}

int Employee::getEmployeeID() const {
	return this->_employeeID;
}

std::string Employee::getPosition() const {
	return this->_position;
}

// display function for employee
void Employee::display() const {
	std::cout << "Name: " << this->getName() << ", employee id: " << this->getEmployeeID() << ", position: " 
		<< this->getPosition() << std::endl;
}
