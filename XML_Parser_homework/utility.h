#pragma once

#include "pugixml.h"

#include "Employee.h"

#include <vector>

std::vector<Employee* > createVectorFromFile(pugi::xml_document &doc) {
    std::vector<Employee*> employees;    

    pugi::xml_node empls = doc.child("EmployeesData").child("Employees");

    for (pugi::xml_node_iterator it = empls.begin(); it != empls.end(); ++it) {
        //pugi::xml_node employeesNode = it->first_child();
        pugi::xml_node workstationNode = it->last_child();

        Workstation* workstation = new Workstation(workstationNode.attribute("Building").as_int(), workstationNode.attribute("Floor").as_int(), workstationNode.attribute("Desc").as_int());
        Employee* employee = new Employee(it->attribute("Name").as_string(), it->attribute("Type").as_string(), it->attribute("Age").as_int(), *workstation);
        
        employees.push_back(employee);

        //delete workstation;
        //workstation = nullptr;
        //delete employee;
        //employee = nullptr;
    }    

    return employees;
}

void printEmployeesInfo(std::vector<Employee*> &employees) {
    if (&employees == nullptr) {
        std::cout << "employees is empty" << std::endl;
    }
    else {
        for (const auto* employee : employees) {
            employee->EmployeeDisplayInfo();
        }
    }
    
}

void deleteEmployees(std::vector<Employee*>& employees) {
    for (auto* employee : employees) {
        std::cout << "\nDeleting in utility" << std::endl;
        delete employee;
        employee = nullptr;
        std::cout << "In utility Employee has been deleted." << std::endl;
    }
}
