#include <iostream>


using namespace std;


// define in header file
class Critters { //class deffinition -- defines a new type, critter

public:
	Critters(int hunger = 0, int boredom = 0); // constructor prototype


	// function prototypes
	void talk();

	void Eat(int food = 4);

	void Play(int fun = 4);
	
private:

	//data memebers
	int m_Hunger;
	int m_Boredom;

	// function prototypes
	int GetMood() const;
	void PassTime(int time = 1);

};

// write funcality in cpp file
// constructor
Critters::Critters(int hunger, int boredom): m_Hunger(hunger), m_Boredom(boredom)
	{

	}

// function

inline int Critters::GetMood() const {
	return(m_Hunger + m_Boredom);
}

void Critters::PassTime(int time) {
	m_Hunger += time;
	m_Boredom += time;
}

void Critters::talk() {
	cout << "I'm a critter and i feel ";
	int mood = GetMood();

	if (mood > 15)
	{
		cout << "mad. \n ";
	}
	else if (mood > 10) {
		cout << "frustrated. \n ";
	}
	else if (mood > 5) {
		cout << "okay. \n ";
	}
	else {
		cout << "happy. \n ";
	}
	PassTime();
}

void Critters::Eat(int food) {
	cout << "Brrupp. \n";

	m_Hunger -= food;

	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}

	PassTime();
}

void Critters::Play(int fun) {
	cout << "wheeeee.\n";

	m_Boredom -= fun;

	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}

	PassTime();
}


int main() {

	Critters crit;

	crit.talk();

	int choice;

	do
	{
		cout << "\nCritter Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your Critter\n";
		cout << "2 - feed your Critter\n";
		cout << "3 - Play with your Critter\n"; 

		cout << "Choice\n";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Good-Bye and Good-Ridance\n";
			break;
		case 1:
			crit.talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		default:
			cout << "\nSorry, but" << choice << "isn't a valid choice.\n";
		}
	} while (choice != 0);
	
	return 0;
}