#include "School.h"

School::School(const std::vector<Class>& c) : classes(c) {}

std::vector<Class> School::getClasses() {
	return this->classes;
}
