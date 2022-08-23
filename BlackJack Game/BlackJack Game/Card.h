#pragma once
#include <iostream>

using namespace std;

class Card
{
public:
	enum rank
	{
		ACE = 1,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING
	};

	enum suit
	{
		CLUB,
		DIAMONDS,
		HEARTS,
		SPADES
	};

	//overloauding << operator so can send Card object to standerd output
	friend ostream& operator<<(ostream& os, const Card& aCard);

	Card(rank r = ACE, suit s = SPADES, bool ifu = true);

	//retuen the value of a card, 1-11
	int GetValue() const;

	//flips a card; if face up, becumes face down and vice versa
	void Flip();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_isFaceUp;
};

