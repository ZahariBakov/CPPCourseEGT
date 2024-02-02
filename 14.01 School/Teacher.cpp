#include "Teacher.h"

Teacher::Teacher(const std::string &name, const std::string &title, const std::vector<Discipline> &disciple)
	: name(name), title(title), disciplines(disciple) {}

std::string Teacher::getName() { 
	return this->name; 
}

std::string Teacher::getTitle() { 
	return this->title;
}

std::vector<Discipline> Teacher::getDisciplines() {
	return this->disciplines;
}
