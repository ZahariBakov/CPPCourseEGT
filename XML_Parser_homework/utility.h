#pragma once

#include "pugixml.h"

#include "Employee.h"

#include <vector>

std::vector<Employee* > createVectorFromFile(pugi::xml_document &doc) {
    std::vector<Employee*> employees;    

    pugi::xml_node empls = doc.child("EmployeesData").child("Employees");

    
    std::string text;

    for (pugi::xml_node_iterator it = empls.begin(); it != empls.end(); ++it) {
        Employee* tempVec = new Employee(it->attribute("Name").as_string(), it->attribute("Type").as_string(), it->attribute("Age").as_int());
        employees.push_back(tempVec);
    }

    

    return employees;
}

void printEmployeesInfo(std::vector<Employee*> &employees) {
    for (const auto* employee : employees) {
        employee->displayInfo();
    }
}
