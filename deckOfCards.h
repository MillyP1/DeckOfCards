#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

enum SUIT { SPADE, DIAMOND, CLUB, HEART };
enum VALUE { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };


class Card
{
    protected:
        VALUE m_value;
        SUIT m_suit;

    public:

        Card (SUIT suit, VALUE value);

        void printCard ();
        VALUE getValue () const;
        SUIT getSuit () const;
        void setValue (VALUE);
        void setSuit (SUIT);

};

class Deck : public Card
{
    private:
        Card m_deck;
        int m_currentCard;

    public:
        Deck ();
        void shuffle ();
        Card deal ();

};

#endif
