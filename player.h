#ifndef PLAYER_H
#define PLAYER_H

#include "deckOfCards.h"
#include <vector>

class Player
{
    protected:
        std::vector <Card> m_hand; 
        

    public:
        Player ();
};

#endif
