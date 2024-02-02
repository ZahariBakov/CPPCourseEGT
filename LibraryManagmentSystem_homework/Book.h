#pragma once

#include <iostream>

class Book {

public:
	// constructor
	Book(std::string, std::string, std::string);

	// setters
	void setTitle(std::string);
	void setAuthor(std::string);
	void setISBN(std::string);

	// getters
	std::string getTitle() const; 
	std::string getAuthor() const;
	std::string getISBN() const;

	// functions
	void display() const;

private:
	// Book variables
	std::string _title;
	std::string _author;
	std::string _ISBN;

};
