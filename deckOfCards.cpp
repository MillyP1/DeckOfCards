#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "randomNumberGenerator.h"
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

    if (getValue () == VALUE::ACE) { name = "A"; }
    if (getValue () == VALUE::JACK) { name = "J"; }
    if (getValue () == VALUE::QUEEN) { name = "Q"; }
    if (getValue () == VALUE::KING) { name = "K"; }

    if (name == "") {
        std::cout << std::left << std::setw (5) << m_value << " of " << std::right << suit << "\n";
    } else std::cout << std::left << std::setw (5) << name << " of " << suit << "\n";
}

Deck::Deck ()
{
    for (int columns = (int)SUIT::SPADE; columns <= (int)SUIT::HEART; columns++) {
        for (int rows = (int)VALUE::ACE; rows <= (int)VALUE::KING; rows++) {
            Card c;
            c.setValue ((VALUE)rows);
            c.setSuit ((SUIT)columns);

            int index = (13 * columns) + rows - 1;
            m_deck.push_back (c);
        }
    } m_deck.shrink_to_fit ();
}

void Deck::printDeck () const
{
    for (int columns = (int)SUIT::SPADE; columns <= (int)SUIT::HEART; columns++) {
        for (int rows = (int)VALUE::ACE; rows <= (int)VALUE::KING; rows++) {
            int index = (13 * columns) + rows - 1;
            m_deck[index].printCard ();
        }
    }
}

void Deck::shuffle ()
{
    std::random_device rd;
    std::default_random_engine rng { rd () };
    std::shuffle (std::begin(m_deck), std::end(m_deck), rng);
}

