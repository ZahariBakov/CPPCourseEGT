#include "PlayingCard.h"
#include "DeckOfCards.h"

#include<cstdlib>
#include <ctime>

static void RandomShuffle(DeckOfCards &deck) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int shuffleTimes = std::rand() % 10 + 1;
    std::cout << shuffleTimes << std::endl;

    for (int i = 0; i < shuffleTimes; ++i) {
        deck.raffleShuffle();
    }
}

int main() {
    DeckOfCards deck;
    deck.createDesk();
    //deck.showDeck();
    //deck.raffleShuffle();
    //deck.raffleShuffle();
    //deck.showDeck();
    RandomShuffle(deck);
    deck.showDeck();

    return 0;
}
