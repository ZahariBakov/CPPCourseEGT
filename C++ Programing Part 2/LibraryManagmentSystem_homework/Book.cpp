#include "Book.h"

// Create new book
Book::Book(std::string title, std::string author, std::string ISBN) {
	setTitle(title);
	setAuthor(author);
	setISBN(ISBN);
}

// Setters to set all book variables. 
// We don't have any set requirements for them, that's why I haven't written any.
void Book::setTitle(std::string title) {
	this->_title = title;
}

void Book::setAuthor(std::string author) {
	this->_author = author;
}

void Book::setISBN(std::string ISBN) {
	this->_ISBN = ISBN;
}

// Getters 
std::string Book::getTitle() const {
	return this->_title;
}

std::string Book::getAuthor() const {
	return this->_author;
}

std::string Book::getISBN() const {
	return this->_ISBN;
}

// Display function for book
void Book::display() const {
	std::cout << "title: " << this->getTitle() << ", author: " << this->getAuthor() 
		<< ", ISBN: " << this->getISBN() << std::endl;
}
