#include "PlayingCard.h"

PlayingCard::PlayingCard(char type, std::string suit) {
	setType(type);
	setSuit(suit);
}

void PlayingCard::setType(char type) {
	while (type != 'A' && type != 'K' && type != 'Q' && type != 'J' && type != 'T' && type != '9' && type != '8' 
		&& type != '7' && type != '6' && type != '5' && type != '4' && type != '3' && type != '2') {
		while (type != 'A' && type != 'K' && type != 'Q' && type != 'J' && type != 'T' && type != '9' && type != '8'
			&& type != '7' && type != '6' && type != '5' && type != '4' && type != '3' && type != '2') {
			std::cout << "Enter a correct type (A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, 2) : " << std::endl;
			std::cin >> type;
		}
	}
	this->_type = type;
}

void PlayingCard::setSuit(std::string suit) {
	if (suit != "spades" && suit != "diamonds" && suit != "hearts" && suit != "clubs") {
		while (suit != "spades" && suit != "diamonds" && suit != "hearts" && suit != "clubs") {
			std::cout << "Enter a right suit (spades, diamonds, hearts or clubs) : " << std::endl;
			std::cin >> suit;
		}
	}

	this->_suit = suit;
}

char PlayingCard::getType() {
	return this->_type;
}

std::string PlayingCard::getSuit() {
	return this->_suit;
}
