#include "Player.h"

Player::Player(const string& name) : GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::IsHitting() const
{
	cout << m_Name << ", do you want a hit? (Y/N): ";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
	cout << m_Name << " wins. \n";
}	
	
void Player::Lose() const
{	
	cout << m_Name << " lose. \n";
}	
	
void Player::Push() const
{	
	cout << m_Name << " pushes. \n";
}