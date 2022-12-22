#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "randomNumberGenerator.h"
#include "deckOfCards.h"
#include "player.h"
Card::Card (VALUE value, SUIT suit)
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
    if (getSuit () == SUIT::SPADE) { suit = "S"; }
    if (getSuit () == SUIT::DIAMOND) { suit = "D"; }
    if (getSuit () == SUIT::CLUB) { suit = "C"; }
    if (getSuit () == SUIT::HEART) { suit = "H"; }

    if (getValue () == VALUE::ACE) { name = "A"; }
    if (getValue () == VALUE::JACK) { name = "JK"; }
    if (getValue () == VALUE::QUEEN) { name = "QN"; }
    if (getValue () == VALUE::KING) { name = "KG"; }

    if (name == "") {
        std::cout << std::right << std::setw (2) << m_value << " | "<< std::right << suit << "\n";
    } else std::cout << std::right << std::setw (2) << name << " | " << suit << "\n";
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
    } std::cout << "Printed...";
}

void Deck::shuffle ()
{
    std::random_device rd;
    std::default_random_engine rng { rd () };
    std::shuffle (m_deck.begin(), m_deck.end(), rng);
}

void Deck::sortNew ()
{
    for (int i = 0; i < m_deck.size(); i++) {
        for (int j = 0; j < m_deck.size(); j++) {
            if ((int)m_deck[i].getValue() < (int)m_deck[j].getValue()) { std::swap (m_deck[i], m_deck[j]); }
            if ((int)m_deck[i].getSuit() < (int)m_deck[j].getSuit()) { std::swap (m_deck[i], m_deck[j]); }
        }
    }
}

void Deck::deal (int numToDeal)
{
    for (int i = 0; i < numToDeal; i++) {
        // Player::addToHand(m_deck[m_deck.size()]);
        m_deck.pop_back();
        m_deck.shrink_to_fit();
    }
}
