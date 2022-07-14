#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

char askYesNo(string question) {
	char response;

	do
	{
		cout << question << " (y/n): ";
		cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}

int RandomNumber(int range) {

	srand(time(0));  // Initialize random number generator.

	for (int i = 0; i < range; i++)
	{
		cout << (rand() % range) + 1 << " ";
		return 0;
	}
}



void Attack(int hp, int dmg, int def, int Edmg) {
	int truedmg;
	int PHP = 100;

	while (PHP >= 0)
	{
		char attack = askYesNo("do you want to attack");

		if (attack == 'y')
		{
			truedmg =  def - RandomNumber(5) * dmg;
			hp = hp - truedmg;
			PHP = PHP - def -Edmg;

			cout << "enemy hp is now: " << hp << "\n";
			cout << "you did " << truedmg << " damage \n";
			cout << "your hp is now: " << PHP << "\n";
			cout << "you took " << Edmg << " damage \n";
			cout << "would you like to attack agian? \n";

			// player hp
			if (PHP <= 0)
			{
				cout << "you died \n";
				exit(3);
			}

			// enemy hp
			if (hp <= 0) {
				cout << "he looks to be dead \n";
				return;
			}
		}
		else
		{
			

			if (RandomNumber(20) <= 10)
			{
				cout << "You ran away" << endl;
				return;
			}
			else
			{
				cout << "You failed to ran away" << endl;
				continue;
			}
			
			
		}

	}

}



int main() {

	int maxHp = 100;
	int HP = maxHp;
	int DMG = 25;
	string attack;
	string flee;

	cout << "current hp is: " << maxHp << "\n";
	cout << "type attack to deal damage \n";

	Attack(HP, DMG, 10, 15);
	

	cout << "well thats thats lets keep moving \n";
	cout << "'wait you'" << "he got back up what should you do" << "'flee, attack'" << "\n";

	if (cin >> flee) {
		cout << "you ran for your life \n";
	}
	else if (cin >> attack)
	{
		//Attack(HP, DMG, 15);
	}

	return 0;
}