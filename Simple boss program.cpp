#include <iostream>

using namespace std;

class Enemy			//base class
{
public:
	Enemy(int Damage = 10);
	void virtual Attack() const;	//made virtual to be overridden
	void virtual Taunt() const;		//made virtual to be overridden

protected:
	int m_Damage;
};

Enemy::Enemy(int Damage) : m_Damage(Damage)
{

}

void Enemy::Attack() const
{
	cout << "Attack Inflits " << m_Damage << " Damage Points!\n";
}

void Enemy::Taunt() const
{
	cout << "The enemy says he will fight you.\n";
}

class Boss : public Enemy			//derived class
{
public:
	Boss(int Damage = 30);
	void SpecialAttack() const;
	void virtual Attack() const;	//optional use of keyword virtual
	void virtual Taunt() const;		//optional use of keyword virtual

private:
	int m_DamageMultiplier;
};

Boss::Boss(int Damage) : m_DamageMultiplier(3), Enemy(Damage)				//call base class constructor with argument
{
	
}

void Boss::SpecialAttack() const
{
	cout << "Special Attack Inflits " << (m_DamageMultiplier * m_Damage);
	cout << " Damage Points!\n";
}

void Boss::Attack() const				//overrides base class function
{
	Enemy::Attack();			//call base class memeber fuction
	cout << " And laughs at you.\n";
}

void Boss::Taunt() const			//overrides base class function
{
	cout << "The boss says he will end you life today.\n";
}

int main()
{
	cout << "Creating an enemy\n";
	Enemy enemy1;
	enemy1.Taunt();
	enemy1.Attack();

	cout << "\nCreating a boss.\n";
	Boss boss1;
	boss1.Taunt();
	boss1.Attack();
	boss1.SpecialAttack();

	return 0;
}