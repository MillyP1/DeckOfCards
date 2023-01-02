#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "randomNumberGenerator.h"
#include "deckOfCards.h"
Card::Card(VALUE value, SUIT suit)
{
    setValue(value);
    setSuit(suit);
}

VALUE Card::getValue() const { return m_name; }
SUIT Card::getSuit() const { return m_suit; }

void Card::setValue(VALUE name)
{
    m_name = name;
    m_value = (int)name;
}
void Card::setSuit(SUIT suit) { m_suit = suit; }

void Card::printCard() const
{
    std::string name = "";
    std::string suit = "";
    if (getSuit() == SUIT::SPADE) { suit = "S"; }
    if (getSuit() == SUIT::DIAMOND) { suit = "D"; }
    if (getSuit() == SUIT::CLUB) { suit = "C"; }
    if (getSuit() == SUIT::HEART) { suit = "H"; }

    if (getValue() == VALUE::ACE) { name = "A"; }
    if (getValue() == VALUE::JACK) { name = "JK"; }
    if (getValue() == VALUE::QUEEN) { name = "QN"; }
    if (getValue() == VALUE::KING) { name = "KG"; }

    if (name == "") {
        std::cout << std::right << std::setw(2) << m_value << " | "<< std::right << suit << "\n";
    } else std::cout << std::right << std::setw(2) << name << " | " << suit << "\n";
}

Deck::Deck(int numOfDecks)
{
    setNumOfDecks(numOfDecks);
    int deckSize = 52 * m_numOfDecks;
    Card tempArray [deckSize];
    m_deck.reserve(deckSize);
    for (int i = 0; i < m_numOfDecks; i++) {
        for (int columns = (int)SUIT::SPADE; columns <= (int)SUIT::HEART; columns++) {
            for (int rows = (int)VALUE::ACE; rows <= (int)VALUE::KING; rows++) {
                Card c;
                c.setValue((VALUE)rows);
                c.setSuit((SUIT)columns);
                
                m_deck.emplace_back(c);
            }
        }
    } m_deck.shrink_to_fit();
}

void Deck::printDeck() const
{
    for (int i = 0; i < m_deck.size(); i++) {
        std::cout << std::right << std::setw(3) << i + 1 << " - " << m_deck.size() << ": ";             // Debugging: Give index of the cards out of total cards in deck
        m_deck[i].printCard();
    } std::cout << "Printed...";
}

void Deck::shuffle()
{
    std::random_device rd;
    std::default_random_engine rng { rd () };
    std::shuffle(m_deck.begin(), m_deck.end(), rng);
}

void Deck::sortNew()
{
    for (int i = 0; i < m_deck.size(); i++) {
        for (int j = 0; j < m_deck.size(); j++) {
            if ((int)m_deck[i].getValue() < (int)m_deck[j].getValue()) { std::swap (m_deck[i], m_deck[j]); }
            if ((int)m_deck[i].getSuit() < (int)m_deck[j].getSuit()) { std::swap (m_deck[i], m_deck[j]); }
        }
    }
}

void Deck::cut() {
    setCutCard();
    if (m_cutCard == 0 || m_cutCard == (m_deck.size() - 1)) { return; }
    for (int i = 0; i < m_cutCard; i++) {
        std::rotate(m_deck.begin(), m_deck.begin() + 1, m_deck.end());
    }
}

void Deck::setCutCard() {
    m_cutCard = generate(0, (m_deck.size() - 1));
    std::cout << m_cutCard << "\n";
}

void Deck::setNumOfDecks(int num) {
    if (num < 1) num = 1;
    if (num > 8) num = 8;
    m_numOfDecks = num;
}
