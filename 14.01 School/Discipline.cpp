#include "Discipline.h"

Discipline::Discipline(const std::string& n, int lectures, int exercises) : name(n), lectureCount(lectures), exerciseCount(exercises) {}

std::string Discipline::getName() {
	return this->name;
}

int Discipline::getLectures() {
	return this->lectureCount;
}

int Discipline::getExrcises() {
	return this->exerciseCount;
}

void Discipline::printDisciplineIfno() {
	std::cout << this->name << " " << this->lectureCount << " " << this->exerciseCount;
}
