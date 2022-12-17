#include <iostream>
#include <vector>
#include "deckOfCards.h"

Card::Card (VALUE value = ACE, SUIT suit = SPADE)
{
    setValue (value);
    setSuit (suit);
}

VALUE Card::getValue () const { return m_name; }
SUIT Card::getSuit () const { return m_suit; }

void Card::setValue (VALUE name)
{
    m_name = name;
    m_value = (int) name;
}
void Card::setSuit (SUIT suit) { m_suit = suit; }

void Card::printCard () const
{
    std::string name = "";
    std::string suit = "";
    if (getSuit () == SUIT::SPADE) { suit = "Spades"; }
    if (getSuit () == SUIT::DIAMOND) { suit = "Diamonds"; }
    if (getSuit () == SUIT::CLUB) { suit = "Clubs"; }
    if (getSuit () == SUIT::HEART) { suit = "Hearts"; }

    if (getValue () == VALUE::ACE) { name = "Ace"; }
    if (getValue () == VALUE::JACK) { name = "Jack"; }
    if (getValue () == VALUE::QUEEN) { name = "Queen"; }
    if (getValue () == VALUE::KING) { name = "King"; }

    if (name == "") {
        std::cout << m_value << " of " << suit << "\n";
    } else std::cout << name << " of " << suit << "\n";
}

Deck::Deck ()
{
    for (int columns = (int)SUIT::SPADE; columns <= (int)SUIT::HEART; columns++) {
        for (int rows = (int)VALUE::ACE; rows <= (int)VALUE::KING; rows++) {
            Card c;
            c.setValue ((VALUE)rows);
            c.setSuit ((SUIT)columns);

            int index = (13 * columns) + rows - 1;
            m_deck [index] = c;
        }
    }
}

void Deck::printDeck () const
{
    for (int columns = (int)SUIT::SPADE; columns <= (int)SUIT::HEART; columns++) {
        for (int rows = (int)VALUE::ACE; rows <= (int)VALUE::KING; rows++) {
            int index = (13 * columns) + rows - 1;
            m_deck [index].printCard ();
        } std::cout << "\n";
    }
}
