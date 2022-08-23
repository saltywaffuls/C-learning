#pragma once
#include <vector>
#include <string>
#include "Deck.h"
#include "House.h"
#include "Player.h"

using namespace std;

class Game
{
public:
	Game(const vector<string>& names);

	~Game();

	// playes the game of blackjack
	void Play();

private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
};

