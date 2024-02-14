#include "Employee.h"

Employee::Employee(std::string name, std::string type, int age, Workstation* wokrSt)
	: name(name), type(type), age(age), workstation(wokrSt) {}

Employee* Employee::parseEmployee(pugi::xml_node employeeNode) {
	std::string name = employeeNode.attribute("Name").value();
	std::string type = employeeNode.attribute("Type").value();
	int age = employeeNode.attribute("Age").as_int();

	Workstation *wPtr = Workstation::parseWorkstation(employeeNode.child("Workstation"));

	return new Employee(name, type, age, wPtr);
}

std::ostream& operator<<(std::ostream& os, const Employee& employee) {
	os << "name: " << employee.name << " type: " << employee.type << " age: " << employee.age << " workstation: "
		<< *employee.workstation;

	return os;
}
