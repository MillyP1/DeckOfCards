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

        Card (VALUE, SUIT);

        void printCard () const;
        void setValue (VALUE);
        void setSuit (SUIT);
        VALUE getValue () const;
        SUIT getSuit () const;

};

class Deck : public Card
{
    private:
        Card m_deck [52];
        int m_currentCard;

    public:
        Deck ();
        void printDeck () const;
        void shuffle ();
        Card deal ();

};

#endif
