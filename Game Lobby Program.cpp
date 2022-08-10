#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
	Player(const string& name = "");
	string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);

private:
	string m_Name;
	Player* m_pNext;		//pointer to next player in list
};

Player::Player(const string& name) : m_Name(name), m_pNext(0) //asinages value/inzilts vars since i didnt do it in the class def
{

}

string Player::GetName() const
{
	return m_Name;
}

Player* Player::GetNext() const
{
	return m_pNext;
}

void Player::SetNext(Player* next)
{
	m_pNext = next;
}


class Lobby
{
	friend ostream& operator<<(ostream& os, const Lobby& aLobby);

public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();

private:
	Player* m_pHead;

};

Lobby::Lobby() : m_pHead(0)			// constructor initalizes the data memeber making it a null pointer
{

}

Lobby::~Lobby()			//destructor removes players obj from list
{
	Clear();
}

void Lobby::AddPlayer()			// add player to the end of the line in the lobby
{
	// makes a new player node
	cout << "Please enter the name of the new player: ";
	string name;
	cin >> name;
	Player* pNewPlayer = new Player(name);

	//if list is empty, make head of list this new player
	if (m_pHead == 0)
	{
		m_pHead = pNewPlayer;
	}
	//otherwise find the end of the list and add the player there
	else
	{
		Player* pIter = m_pHead;
		while (pIter->GetNext() !=0)
		{
			pIter = pIter->GetNext();
		}
		pIter->SetNext(pNewPlayer);
	}
}

void Lobby::RemovePlayer()
{
	if (m_pHead == 0)
	{
		cout << "The Game Loby is empty. no one to remove!\n";
	}
	else
	{
		Player* pTemp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete pTemp;
	}
}

void Lobby::Clear()				//removes all players from the lobby
{
	while (m_pHead != 0)
	{
		RemovePlayer();
	}
}

ostream& operator<<(ostream& os, const Lobby& aLobby)			//overloads the << operator so i can display a lobby
{
	Player* pIter = aLobby.m_pHead;

	os << "\nHere's who's in the game Lobby:\n";
	if (pIter == 0)
	{
		os << "The lobby is empty.\n";
	}
	else
	{
		while (pIter != 0)
		{
			os << pIter->GetName() << endl;
			pIter = pIter->GetNext();
		}
	}
	return os;
}

int main()
{
	Lobby myLobby;
	int choice;

	do
	{
		cout << myLobby;
		cout << "\nGame Lobby\n";
		cout << "0 - Exit the program.\n";
		cout << "1 - Add a Player to the lobby.\n";
		cout << "2 - Removes Player from lobby.\n";
		cout << "3 - Clears the lobby.\n";
		cout << endl << "Enter Choice: ";

		cin >> choice;

		switch (choice)
		{
		case 0: cout << "Good-Bye. \n";
			break;
		case 1: myLobby.AddPlayer();
			break;
		case 2: myLobby.RemovePlayer();
			break;
		case 3: myLobby.Clear();
			break;
		default: cout << "Thats was not A Valid choice. \n";
		}
	} while (choice != 0);

	return 0;
}