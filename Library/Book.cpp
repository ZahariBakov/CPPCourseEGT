#include "Book.h"

Book::Book(std::string title, std::string genre, int year, Author a) : author(a) {
	setTitle(title);
	setGenre(genre);
	setYear(year);
}

void Book::setTitle(std::string title) {
	this->title = title;
}

void Book::setGenre(std::string g) {
	this->genre = g;
}

void Book::setYear(int y) {
	this->year = y;
}

std::string Book::getTitle() const {
	return this->title;
}

std::string Book::getGenre() const {
	return this->genre;
}

int Book::getYear() const {
	return this->year;
}

void Book::print() const {
	std::cout << this->getTitle() << " " << this->getYear() << " " << this->getGenre() << std::endl;
	author.print();
}
