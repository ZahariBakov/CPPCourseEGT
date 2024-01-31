#include "Shop.h"

#include <map>

Shop::Shop(std::vector<User*> users) : _users(users) {}

void Shop::soldDrinks() {
	std::map<std::string, int> soldProducts;
	int soldAlcoholic = 0;
	int soldNonAlcoholic = 0;

	for (size_t i = 0; i < _users.size(); ++i) {
		auto userOrders = _users[i]->getOrders();

		for (auto order : userOrders) {
			auto userDrinks = order->getDrinks();

			for (auto drink : userDrinks) {
				Alcoholic* alcoholic = dynamic_cast<Alcoholic*>(drink);

				if (alcoholic) {
					soldAlcoholic++;
				}
				else {
					soldNonAlcoholic++;
				}

				soldProducts[drink->getName()]++;
			}
		}
	}

	std::cout << "Alcoholic: " << soldAlcoholic << " non alcoholic: " << soldNonAlcoholic << std::endl;

	for (auto product : soldProducts) {
		std::cout << "From " << product.first << " sold " << product.second << std::endl;
	}
}

void Shop::bestClient() {
	double bestPrice = 0;
	User* bestUserPtr{};
	double currPrice = 0.0;

	for (auto user : _users) {
		for (auto order : user->getOrders()) {
			currPrice += order->calculateTotalPrice();
		}

		if (currPrice > bestPrice) {
			bestUserPtr = user;
			bestPrice = currPrice;
		}

		currPrice = 0.0;
	}

	std::cout << "Best client is: " << bestUserPtr->getUsername() << " He has spent: " << bestPrice  << " with orders: " << std::endl;
	bestUserPtr->printBill();
}

void Shop::searchByDrinks(std::string type) {
	std::cout << "Searching for " << type << "...\n";
	for (auto user : _users) {
		for (auto order : user->getOrders()) {
			for (auto drink : order->getDrinks()) {
				if (type == drink->getType()) {
					std::cout << user->getUsername() << std::endl;
					drink->print();
				}
			}
		}
	}
	std::cout << std::endl;

}

void Shop::searchByDrinksAndMoney(std::string type, double price) {
	std::cout << "Searching for " << type << " over price " << price << "...\n";
	for (auto user : _users) {
		for (auto order : user->getOrders()) {
			for (auto drink : order->getDrinks()) {
				if (type == drink->getType()) {
					if (price < drink->calculatePrice()) {
						std::cout << user->getUsername() << std::endl;
						drink->print();
					}	
				}
			}
		}
	}
	std::cout << std::endl;
}
