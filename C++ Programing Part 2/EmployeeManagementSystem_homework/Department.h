#pragma once

#include <vector>

#include "Employee.h"

class Department {

public:
	// constructor
	Department(std::string);

	// seters
	void setDepartmentName(std::string);
	
	// getters
	std::string getDepartmentName() const;

	// functions
	void addEmployee(Employee*);
	void displayEmployees();

private:
	std::string            _departmentName;
	std::vector<Employee*> _employees;
	int                    _numEmployees;

};
