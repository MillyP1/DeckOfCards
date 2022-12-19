#include <iostream>
#include <algorithm>
#include <vector>
#include "deckOfCards.h"

int main () {
    std::cout << "Hello!\nThis is a deck of card!\n\n";

    Deck deck;
    std::cout << "Ordered deck:\n";
    deck.printDeck ();
    deck.shuffle ();
    std::cout << "\n\nShuffled deck:\n";
    deck.printDeck ();

    return 0;
}
