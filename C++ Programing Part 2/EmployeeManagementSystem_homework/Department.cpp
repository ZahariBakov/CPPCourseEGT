#include "Department.h"

Department::Department(std::string name) {
	setDepartmentName(name);
	this->_numEmployees = 0;
}

// Setter to set Department variable. 
// We don't have any set requirements for them, that's why I haven't written any.
void Department::setDepartmentName(std::string name) {
	this->_departmentName = name;
}

// getter
std::string Department::getDepartmentName() const {
	return this->_departmentName;
}


// function that adds a new employee
void Department::addEmployee(Employee* employee) {
	this->_employees.push_back(employee);
	this->_numEmployees++;
}

// display function for department and every employee
void Department::displayEmployees() {
	std::cout << "Department name: " << this->getDepartmentName() << std::endl;
	for (auto employee : this->_employees) {
		employee->display();
	}
	std::cout << std::endl;
}
