#include "PlayingCard.h"
#include "DeckOfCards.h"


int main() {
    DeckOfCards deck;
    deck.createDesk();
    deck.showDeck();
    deck.raffleShuffle();
    deck.raffleShuffle();
    deck.showDeck();

    return 0;
}
