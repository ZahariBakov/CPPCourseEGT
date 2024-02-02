#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
public:
	Book(std::string, std::string, int, double);

	void setAuthor(std::string);
	void setTitle(std::string);
	void setYear(int);
	void setPrice(double);
	
	std::string getAuthor();
	std::string getTitle();
	int getYear();
	double getPrice();

	void displayMessage();

private:
	std::string author;
	std::string title;
	int yearOfIssue;
	double price;
};

#endif // !BOOK_H
