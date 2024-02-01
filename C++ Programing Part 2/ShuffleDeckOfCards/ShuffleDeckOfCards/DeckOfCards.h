#pragma once

#include "PlayingCard.h"

class DeckOfCards {

public:

	void createDesk();
	void raffleShuffle();
	void showDeck();

private:

	char _arrType[13] = { 'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2' };
	std::string _arrSuit[4] = { "spades", "diamonds", "hearts", "clubs" };
	std::vector<PlayingCard> _deck;

};
