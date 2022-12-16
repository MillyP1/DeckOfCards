#include <iostream>
#include <vector>
#include "deckOfCards.h"


Card::Card (SUIT suit, VALUE value)
{

}

VALUE Card::getValue () const { return m_value; }

SUIT Card::getSuit () const { return m_suit; }

void Card::setValue (VALUE value)
{
    m_value = value;
}

void Card::setSuit (SUIT suit)
{
    m_suit = suit;
}
