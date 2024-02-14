#pragma once

#include <vector>

#include "Employee.h"

class EmployeeService {
public:
	static void parseEmployeesData();

	static std::vector<Employee*> getEmployeesList();

private:
	static std::vector<Employee*> employeesList;
	static pugi::xml_document doc;
};
