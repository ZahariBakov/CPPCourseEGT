#pragma once

#include "Book.h"

class Member {

public:
	// constructor
	Member(std::string, int, std::string);

	// setters
	void setName(std::string);
	void setAge(int);
	void setMemberID(std::string);

	// getters
	std::string getName() const;
	int         getAge() const;
	std::string getMemberID() const;

	// functions
	void display() const;
	void borrowBook(Book*);

private:
	// Member variables
	std::string _name;
	int         _age;
	std::string _memberID;

};
