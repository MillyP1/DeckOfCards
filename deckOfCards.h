#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <vector>

enum SUIT { SPADE, DIAMOND, CLUB, HEART };
enum VALUE { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };


class Card
{
    protected:
        VALUE m_name;
        SUIT m_suit;
        int m_value;

    public:

        Card (VALUE value = ACE, SUIT suit = SPADE);

        virtual void printCard () const;
        void setValue (VALUE);
        void setSuit (SUIT);
        VALUE getValue () const;
        SUIT getSuit () const;
};

class Deck : public Card
{
    private:
        std::vector <Card> m_deck;
        int m_currentCard;

    public:
        Deck ();
        void printDeck () const;
        void shuffle ();
        void sortNew ();

};

#endif
