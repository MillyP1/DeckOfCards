#include <iostream>
#include <algorithm>
#include <vector>
#include "deckOfCards.h"

int main () {
    std::cout << "Hello!\nThis is a deck of card!\n\n";

    Deck deck(2);
    std::cout << "Ordered deck:\n";
    deck.printDeck();
    std::cout << "\n\nShuffled deck:\n";
    deck.shuffle();
    deck.printDeck();
    // std::cout << "\n\nRe-ordered deck:\n"; 
    // deck.sortNew();
    // deck.printDeck();
    std::cout << "\n\nCut deck:\n";
    deck.cut();
    deck.printDeck();
}
