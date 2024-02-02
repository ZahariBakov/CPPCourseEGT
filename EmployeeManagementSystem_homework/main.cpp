#include "Employee.h"
#include "Department.h"

int main() {
    // create employees
    Employee firstEmployee("Ivan Petrov", 10235, "Intern");
    Employee secondEmployee("Georgi Stoilov", 25463, "Intern");
    Employee thirdEmployee("Maria Ignatova", 12387, "Junior staffer");
    Employee fourthEmployee("Lora Stoianova", 54102, "Junior staffer");
    Employee fifthEmployee("Victor Georgiev", 30245, "Senior staffer");
    Employee sixthEmployee("Zahari Ivanov", 10233, "Team leader");
    Employee seventhEmployee("Ivailo Belev", 45632, "Junior staffer");
    Employee eighthEmployee("Yana Dimitrova", 10021, "CEO");

    // testing employees
    //std::cout << thirdEmployee.getName() << std::endl;
    //std::cout << fifthEmployee.getEmployeeID() << std::endl;
    //std::cout << eighthEmployee.getName() << std::endl;
    //std::cout << firstEmployee.getPosition() << std::endl;

    // create vector of employyes
    std::vector<Employee*> employeesVec{ &firstEmployee, &secondEmployee, &thirdEmployee };
    employeesVec.push_back(&fourthEmployee);
    employeesVec.push_back(&fifthEmployee);
    employeesVec.push_back(&sixthEmployee);
    employeesVec.push_back(&seventhEmployee);
    employeesVec.push_back(&eighthEmployee);

    // create two departments
    Department firstDepartment("Some kind of job");
    Department* secondDepartment = new Department("Concrete junction");

    // add employees to department vectors
    for (size_t i = 0; i < employeesVec.size(); ++i) {
        if (i % 2 == 0) {
            firstDepartment.addEmployee(employeesVec[i]);
        }
        else {
            secondDepartment->addEmployee(employeesVec.at(i));
        }
    }

    // display departments
    firstDepartment.displayEmployees();
    secondDepartment->displayEmployees();

    return 0;
}
