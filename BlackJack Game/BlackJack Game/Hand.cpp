#include "Hand.h"

Hand::Hand()
{
	m_Cards.reserve(7);
}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}

void Hand::Clear()
{
	//iterate througe vector, freeing all memory on the heap
	vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++)
	{
		delete *iter;
		*iter = 0;
	}
	//clears vector pointers
	m_Cards.clear();
}

int Hand::GetTotal() const
{
	//if no cards in hand, return 0
	if (m_Cards.empty())
	{
		return 0;
	}

	//if a first card has value of 0, then card is face doawn; return 0
	if (m_Cards[0]->GetValue() == 0)
	{
		return 0;
	}

	//add up card values, treat each ace as 1
	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++)
	{
		total += (*iter)->GetValue();
	}

	//deternine if  hand contains an ace
	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++)
	{
		if ((*iter)->GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}

	//if hand contains ace and total is low enough, treat ace as 11
	if (containsAce && total <= 11)
	{
		//add only 10 since we've already added 1 for the ace
		total += 10;
	}

	return total;
}