#include "Book.h"

Book::Book(std::string author, std::string title, int yearOfIssue, double price) {
	setAuthor(author);
	setTitle(title);
	setYear(yearOfIssue);
	setPrice(price);
}

void Book::setAuthor(std::string author) {
	this->author = author;
}

void Book::setTitle(std::string title) {
	this->title = title;
}

void Book::setYear(int yearOfIssue) {
	if (yearOfIssue > 1880 && yearOfIssue < 2024) {
		this->yearOfIssue = yearOfIssue;
	}
	else {
		this->yearOfIssue = 1990;
		std::cout << "Invalid year. Year must be between 1880 and 2024. Year is set automatically to 1990." << std::endl;
	}
	
}

void Book::setPrice(double price) {
	if (price <= 0) {
		this->price = 15.00;
		std::cout << "Invalid price. Price must be positive number. Price is set automatically to 15.00." << std::endl;
	}
	else if (price > 1500) {
		this->price = 250.00;
		std::cout << "Too big price. You sell a book, not a car. Price is set automatically to 250.00." << std::endl;
	}
	else {
		this->price = price;
	}
}

std::string Book::getAuthor() {
	return this->author;
}

std::string Book::getTitle() {
	return this->title;
}

int Book::getYear() {
	return this->yearOfIssue;
}

double Book::getPrice() {
	return this->price;
}

void Book::displayMessage() {
	std::cout << "Author: " << getAuthor()
		<< ", Book Title: " << getTitle()
		<< ", Year of issue: " << getYear()
		<< ", price: " << getPrice()
		<< std::endl;
}
