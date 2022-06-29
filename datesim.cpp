#include <iostream>
#include <string>

using namespace std;

float IncreaseAffection(float affection, float answer) {
	affection = affection + answer;
	return affection;
}

float DecreaseAffection(float affection, float answer) {
	affection = affection - answer;
	return affection;
}

bool GiveGift(int gift , string give) {
	cin >> give;
	gift = gift - 1;

	if (gift <= 0)
		cout << " you don't have any gifts left \n";
	return true;
}

void GiveAnswer(string answer) {
	cin >> answer;
}

int main() {
	float LaraPrachiaffetction = 50.0f;
	float Phyllisaffetction = 50.0f;
	float RoxanneMalenaaffetction = 50.0f;
	string Girls[] {"Phyllis Ji-Min","Lara Prachi","Roxanne Malena"};
	char response;
	

	int gifts = 3;

	cout << "its your first day of school and your surrond by bwutifull girls \n";
	cout << "hay you there \n" << Girls[0] << " calls out to you \n";
	cout << "'thats not this schools standerd dress code' \n";

	

	cout << Girls[0] << " current affection is: " << Phyllisaffetction << "\n";
	cout << "replay" << " sorry = y or fuck off = n\n";

	cin >> response;

	if (response == 'y') {
		Phyllisaffetction = IncreaseAffection(Phyllisaffetction, 10.0f);
		cout << Girls[0] << " current affection is: " << Phyllisaffetction << "\n";
		cout << "you said SORRY\n";
		cout << Girls[0] << " 'well dont let it happen agian' says \n";
		cout << "whould you like to give her a gift? (yes or no)";

		char gift;

		cin >> gift;

		if (gift == 'y') {
			gifts = gifts - 1;
			Phyllisaffetction = IncreaseAffection(Phyllisaffetction, 20.0f);
			cout << Girls[0] << " current affection is: " << Phyllisaffetction << "\n";
			cout << "you have: " << gifts << " gifts left\n";
			cout << "um thanks" << Girls[0] << " says\n";
		}
		else if (gift == 'n') {
			cout << "you did not give " << Girls[0] << " a gift\n";
			cout << "you have: " << gifts << " gifts left\n";
		}

	}
	else if (response == 'n')
	{
		Phyllisaffetction = DecreaseAffection(Phyllisaffetction, 10.0f);
		cout << Girls[0] << "current affection is: " << Phyllisaffetction << "\n";
		cout << Girls[0] << " 'gasps' \n";

	}

	cout << Girls[0] << " walks away " << "the bell rings you run to class\n";
		
	


	return 0;
}
