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

        Card(VALUE value = ACE, SUIT suit = SPADE);

        virtual void printCard() const;
        void setValue(VALUE);
        void setSuit(SUIT);
        VALUE getValue() const;
        SUIT getSuit() const;
};

class Deck : public Card
{
    private:
        std::vector <Card> m_deck;
        int m_numOfDecks = 1;
        int m_currentCard;
        int m_cutCard = 0;

    public:
<<<<<<< HEAD
        Deck ();
        void printDeck () const;
        void shuffle ();
        void sortNew ();

=======
        Deck(int numOfDecks = 1);
        void printDeck() const;
        void shuffle();
        void sortNew();
        void cut();
        void setCutCard();
        void setNumOfDecks(int);
>>>>>>> a9d602c (Added funcionality to "place a cut card" and cutting the deck. In addition, small updates to code.)
};

#endif
