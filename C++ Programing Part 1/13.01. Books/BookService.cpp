#include "BookService.h"

Book BookService::inputData() {
	std::string author;
	std::string title;
	int yearOfIssue;
	double price;

	std::cout << "Enter Author: ";
	std::getline(std::cin >> std::ws, author);

	std::cout << "Enter Book title: ";
	std::getline(std::cin>>std::ws, title);

	std::cout << "Enter Year of issue: ";
	std::cin >> yearOfIssue;
	std::cin.ignore(1000, '\n');

	std::cout << "Enter price: ";
	std::cin >> price;
	std::cin.ignore(1000, '\n');

	std::cout << std::endl;

	Book myBook(author, title, yearOfIssue, price);

	return myBook;
}