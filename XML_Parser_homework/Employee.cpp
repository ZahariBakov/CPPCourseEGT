#include "Employee.h"

Employee::Employee(std::string name, std::string type, int age, Workstation& workstation) {
	setName(name);
	setType(type);
	setAge(age);
	this->_workstation = &workstation;
}

Employee::~Employee() {
	delete this->_workstation;
	this->_workstation = nullptr;
}

void Employee::setName(std::string name) {
	this->_name = name;
}

void Employee::setType(std::string type) {
	this->_type = type;
}

void Employee::setAge(int age) {
	this->_age = age;
}

void Employee::EmployeeDisplayInfo() const {
	std::cout << "Name: " << getName() << " Type: " << getType() << " Age: " << getAge() << std::endl;

	if (_workstation == nullptr) {
		std::cout << "Workstation is empty" << std::endl;
	}
	else {
		this->_workstation->WorkstationDisplayInfo();
	}
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
