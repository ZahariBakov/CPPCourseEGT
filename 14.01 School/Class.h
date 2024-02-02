#pragma once

#include "Teacher.h"
#include "Student.h"

class Class {
public:
	Class(const std::string&, const std::vector<Teacher>&, const std::vector<Student>&);

	std::string getIdentifier();
	std::vector<Teacher> getTeachers();
	std::vector<Student> getStudents();

private:
	std::string identifier;
	std::vector<Teacher> teachers;
	std::vector<Student> students;
};
