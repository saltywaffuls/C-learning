#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void Attack(int hp, int dmg) {
	string attack;
	int truedmg;

	while (cin)
	{
		cin >> attack;
		truedmg = rand() % dmg;
		hp = hp - truedmg;

		cout << "hp is now: " << hp << "\n";
		cout << "you did " << truedmg << " damage \n";
		cout << "would you like to attack agian? \n";

		

		if (hp <= 0) {
			cout << "he looks to be dead \n";
			return;
		}

	}

}

int main() {
	/*const int Max_Items = 10;
	string inventory[Max_Items];

	int numItem = 0;
	inventory[numItem++] = "sword";
	inventory[numItem++] = "shield";
	inventory[numItem++] = "armor";

	cout << "your item: \n";
	for (int i = 0; i < numItem; i++) {
		cout << inventory[i] << endl;
	}

	cout << "\nyou traded your sword for a axe.";
	inventory[0] = "axe";
	cout << "\nin your items:\n";
	for (int i = 0; i < numItem; i++) {
		cout << inventory[i] << endl;
	}

	cout << "\nThe item name '" << inventory[0]<<"'has";
	cout << inventory[0].size() << "letters in it.\n";

	cout << "\nYou find a healing potion.";

	if (numItem < Max_Items) {
		inventory[numItem++] = "healing potion";
	}
	else {
		cout << " you have to many items and can't carry more.";
	}

	cout << "\nYour items:\n";
	for (int i = 0; i < numItem; i++) {
		cout << inventory[i] << endl;
	}*/

	int maxHp = 100;
	int HP = maxHp;
	int DMG = 25;
	string attack;
	string flee;

	cout << "current hp is: " << maxHp << "\n";
	cout << "type attack to deal damage \n";
	
	Attack(HP,DMG);

	cout << "well thats thats lets keep moving \n";
	cout << "'wait you'" << "he got back up what should you do" << "'flee, attack'" << "\n";

	if (cin >> flee) {
		cout << "you ran for your life \n";
	}
	else if(cin >> attack)
	{
		Attack(HP, DMG);
	}

	return 0;
}
