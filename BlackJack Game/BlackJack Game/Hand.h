#pragma once
#include <vector>
#include "Card.h"

using namespace std;

class Hand
{
public:
	Hand();

	virtual ~Hand();

	//adds a card to hand
	void Add(Card* pCard);

	//clears hand of all cards
	void Clear();

	//gets hand total value, intelligently treats ace as 1 or 11
	int GetTotal() const;

protected:
	vector<Card*> m_Cards;
};

