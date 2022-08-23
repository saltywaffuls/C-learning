#include "Card.h"


Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_isFaceUp(ifu)
{}

int Card::GetValue() const
{
//if a cad is face down, its value is 0
	int value = 0;
	if (m_isFaceUp)
	{
		//value is number showing on card
		value = m_Rank;
		//value is 10 for face cards
		if (value > 10)
		{
			value = 10;
		}
	}
	return value;
}

void Card::Flip()
{
	m_isFaceUp = !(m_isFaceUp);
}