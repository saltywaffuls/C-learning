#pragma once
#include <string>
#include "GenericPlayer.h"
class Player :
    public GenericPlayer
{
public:
    Player(const string& name = "");

    virtual ~Player();

    //returns whether or not player wants anouther hit
    virtual bool IsHitting() const;

    //announces that the player won
    void Win() const;

    //announces that the player loses
    void Lose() const;

    //announces that the player pushes
    void Push() const;
};

