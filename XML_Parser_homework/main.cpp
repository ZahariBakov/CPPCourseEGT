#include "utility.h"

int main() {
    pugi::xml_document doc;

    if (!doc.load_file("employees.xml")) {
        return -1;
    }

    std::vector<Employee*> employees = createVectorFromFile(doc);
    printEmployeesInfo(employees);
    deleteEmployees(employees);

    return 0;
}
