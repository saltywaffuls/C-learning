#include <iostream>

using namespace std;

class Enemy
{
public:
	Enemy(int damage = 10);
	virtual ~Enemy();
	void virtual Attack() const;

protected:
	int* m_pDamage;
};

Enemy::Enemy(int damage)
{
	m_pDamage = new int(damage);
}

Enemy::~Enemy()
{
	cout << "in Enemy destructor, deleteing m_pDamage.\n";
	delete m_pDamage;
	m_pDamage = 0;
}

void Enemy::Attack() const
{
	cout << "An Enemy attacks and deals " << *m_pDamage << " Damage points.";
}

class Boss : public Enemy
{
public:
	Boss(int multiplier = 3);
	virtual ~Boss();
	void virtual Attack() const;

protected:
	int* m_pMultiplier;
};

Boss::Boss(int multiplier)
{
	m_pMultiplier = new int(multiplier);
}

Boss::~Boss()
{
	cout << "in Boss destructor, deleteing m_pMultiplier.\n";
	delete m_pMultiplier;
	m_pMultiplier = 0;
}

void Boss::Attack() const
{
	cout << "An Enemy attacks and deals " << (*m_pDamage) * (*m_pMultiplier);
	cout << " Damage points.";
}


int main()
{
	cout << "Calling Attack() on Boss obj theough pointer to Enemy:\n";
	Enemy* pBadguy = new Boss();
	pBadguy->Attack();
	
	cout << "\n\nDeleting pointer to Enemy: \n";
	delete pBadguy;
	pBadguy = 0;

	return 0;
}