#include "Discipline.h"
#include "Teacher.h"
#include "Student.h"
#include "Class.h"
#include "School.h"

int main() {
    // Create disciplines
    Discipline math("Math", 20, 10);
    Discipline physics("Physics", 15, 8);
    Discipline history("History", 45, 69);

    // Create teachers
    Teacher teacher1("John Doe", "Professor", { math, physics });
    Teacher teacher2("Alice Smith", "Assistant Professor", { math, history });

    Teacher teacher3("Michael Brown", "Professor", { history, physics });
    Teacher teacher4("Jennifer Williams", "Assistant Professor", { math, physics });

    // Create students
    Student student1("Bob", 1);
    Student student2("Emma", 2);
    Student student3("Jessice", 3);
    Student student4("David", 4);

    Student student5("Richard", 1);
    Student student6("Daniel", 2);
    Student student7("Nancy", 3);
    Student student8("Betty", 4);

    // Create classes
    Class class1("ClassA", { teacher1, teacher2 }, { student1, student2, student3, student4 });
    Class class2("ClassB", { teacher3, teacher4 }, { student5, student6, student7, student8 });

    // Create school
    School school({ class1, class2 });

    // Print sample school information
    std::cout << "School Information:\n";
    for (auto& schoolClass : school.getClasses()) {
        std::cout << "Class Identifier: " << schoolClass.getIdentifier() << "\n";
        for (auto& teacher : schoolClass.getTeachers()) {
            std::cout << "  Teacher: " << teacher.getName() << ", Title: " << teacher.getTitle() << "\n";
            for (auto& discipline : teacher.getDisciplines()) {
                std::cout << "    Discipline: " << discipline.getName() << ", Lectures: "
                    << discipline.getLectures() << ", Exercises: " << discipline.getExrcises() << "\n";
            }
        }
        for (auto& student : schoolClass.getStudents()) {
            std::cout << "  Student: " << student.getName() << ", Class Number: " << student.getClassNumber() << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
