#include <iostream>

#include "pugixml.h"

//using namespace pugi;

int main() {
    pugi::xml_document doc;

    if (!doc.load_file("employees.xml")) {
        return -1;
    }

    pugi::xml_node empls = doc.child("EmployeesData").child("Employees");

    for (pugi::xml_node_iterator it = empls.begin(); it != empls.end(); ++it) {
        std::cout << "Employee: ";

        for (pugi::xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait) {
            std::cout << " " << ait->name() << " = " << ait->value();
        }

        std::cout << std::endl;
    }

    return 0;
}
