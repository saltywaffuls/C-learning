#pragma once
#include <iostream>
#include <string>
#include "Hand.h"

using namespace std;

class GenericPlayer :
    public Hand
{
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const string& name = "");

    virtual ~GenericPlayer();

    //indicates whether or not GenericPlayer wanst to keep hitting
    virtual bool IsHitting() const = 0;

    //retruns whether or not GenericPlayer has busted - has a total greater then 21
    bool IsBusted() const;

    //announces that the GenericPlayer busts
    void Bust() const;

protected:
    string m_Name;
};

