#include "Book.h"

Book::Book(std::string bookName, std::string genre, int year, Author author) : _author(author) {
	setBookName(bookName);
	setGenre(genre);
	setYear(year);
}

void Book::setBookName(std::string bookName) {
	this->_bookName = bookName;
}

void Book::setGenre(std::string genre) {
	int chose;

	std::cout << "Enter your choice of genre for " << this->getBookName() << ": " << std::endl;
	std::cout << "For classic      press 1 " << std::endl;
	std::cout << "For children     press 2 " << std::endl;
	std::cout << "For fantastic    press 3 " << std::endl;
	std::cout << "For biographical press 4 " << std::endl;
	std::cout << "For love         press 5 " << std::endl;
	std::cin >> chose;

	switch (chose) {
	case 1:
		genre = "Classic";
		break;
	case 2:
		genre = "Children";
		break;
	case 3:
		genre = "Fantastic";
		break;
	case 4:
		genre = "Biographical";
		break;
	case 5:
		genre = "Love";
		break;
	default:
		std::cout << "Invalid choise. Genre set to Classic." << std::endl;
		genre = "Classic";
		break;
	}

	this->_ganre = genre;
}

void Book::setYear(int year) {
	this->_year = year;
}

std::string Book::getBookName() {
	return this->_bookName;
}

std::string Book::getGenre() {
	return this->_ganre;
}

int Book::getYear() const {
	return this->_year;
}

void Book::print() {
	std::cout << "Book: " << this->getBookName() << " " << this->getGenre() << " " << this->getYear() << " from ";
	_author.print();
	std::cout << std::endl;
}
