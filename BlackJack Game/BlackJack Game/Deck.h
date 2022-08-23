#pragma once
#include "Hand.h"
#include "GenericPlayer.h"

class Deck :
    public Hand
{
public:
    Deck();

    virtual ~Deck();

    //creates a standed deck of 52 cards
    void Populate();

    //shuffles cards
    void Shuffle();

    //deal one card
    void Deal(Hand& aHand);

    //gives additional cards to generic player
    void AdditionalCards(GenericPlayer& aGenericPlayer);
};

