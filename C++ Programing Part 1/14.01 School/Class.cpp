#include "Class.h"

Class::Class (const std::string& id, const std::vector<Teacher>& t, const std::vector<Student>& s)
	: identifier(id), teachers(t), students(s) {}

std::string Class::getIdentifier() { 
	return identifier; 
}

std::vector<Teacher> Class::getTeachers() { 
	return teachers; 
}

std::vector<Student> Class::getStudents() { 
	return students; 
}
