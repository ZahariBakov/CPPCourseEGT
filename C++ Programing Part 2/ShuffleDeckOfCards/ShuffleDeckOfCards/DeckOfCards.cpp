#include "DeckOfCards.h"

void DeckOfCards::createDesk() {
    char        currType;
    std::string currSuit;
    std::string currCard;

    for (int i = 0; i < 13; ++i) {
        currType = this->_arrType[i];
        for (int j = 0; j < 4; ++j) {
            currSuit = this->_arrSuit[j];
            PlayingCard currCard(currType, currSuit);
            this->_deck.push_back(currCard);
        }
    }
}

void DeckOfCards::raffleShuffle() {
    std::vector<PlayingCard> firstPartOfDeck[26];
    std::vector<PlayingCard> secondPartOfDeck[26];

    for (int i = 0; i < 52; ++i) {
        if (i % 2 == 0) {
            firstPartOfDeck->push_back(this->_deck[i]);
        }
        else {
            secondPartOfDeck->push_back(this->_deck[i]);
        }
    }
}

void DeckOfCards::showDeck() {
    for (size_t i = 0; i < this->_deck.size(); ++i) {
        std::cout << this->_deck[i].getType() << " " << this->_deck[i].getSuit() << std::endl;
    }
}
