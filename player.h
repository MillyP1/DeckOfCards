#ifndef PLAYER_H
#define PLAYER_H

#include "deckOfCards.h"
#include <vector>

class Player
{
    protected:
        std::vector <Card> m_hand; 
        

    public:
<<<<<<< HEAD
        Player ();
=======
        Player();
        void addToHand(Card cardDealt);
>>>>>>> a9d602c (Added funcionality to "place a cut card" and cutting the deck. In addition, small updates to code.)
};

#endif
