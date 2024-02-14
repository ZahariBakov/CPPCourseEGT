#include "EmployeeService.h"

pugi::xml_document EmployeeService::doc;
std::vector<Employee*> EmployeeService::employeesList;

void EmployeeService::parseEmployeesData() {
	// open file
	// go to EmployeesData.Employees node
	// loop true all Employee
	// read the Employee node -> parseEmployee; // return employee (Employee object)
	// add employee object to vector

	if (!doc.load_file("sample.xml")) {
		std::cout << "Invalid file!" << std::endl;
		return;
	}

	pugi::xml_node employees = doc.child("EmployeesData").child("Employees");

	//for (pugi::xml_node employee = employees.child("Employee"); employee; employee = employee.next_sibling("Employee")) {
	//
	//}

	for (auto employee : employees) {
		Employee* ePtr = Employee::parseEmployee(employee);
		employeesList.push_back(ePtr);
	}
}

std::vector<Employee*> EmployeeService::getEmployeesList() {
	return employeesList;
}
