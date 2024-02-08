#include "pugixml.h"

#include "Employee.h"

#include <vector>

int main() {
    pugi::xml_document doc;

    if (!doc.load_file("employees.xml")) {
        return -1;
    }

    pugi::xml_node empls = doc.child("EmployeesData").child("Employees");

    std::vector<Employee*> employees;
    std::string text;

    for (pugi::xml_node_iterator it = empls.begin(); it != empls.end(); ++it) {        
        Employee* tempVec = new Employee(it->attribute("Name").as_string(), it->attribute("Type").as_string(), it->attribute("Age").as_int());
        employees.push_back(tempVec);
    }

    for (size_t i = 0; i < employees.size(); ++i) {
        employees[i]->displayInfo();
    }

    return 0;
}
