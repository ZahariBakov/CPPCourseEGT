#include "EmployeeService.h"

int main() {
    EmployeeService::parseEmployeesData();

    for (auto employee : EmployeeService::getEmployeesList()) {
        std::cout << *employee << std::endl;
    }

    return 0;
}
