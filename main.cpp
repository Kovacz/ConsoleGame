#include <iostream>
#include <string>
#include <random> 
#include <ctime>
#include <iomanip> 
using namespace std;
class Human;
class Weapon;
class Mage;
class Game;

enum class HitResult
{
	Incorrect, Missed, Wounded, Killed, Suicide, Heal
};

class Weapon
{
public:
	double damage;
	string Name;
	Human *owner;
public:
	Weapon(double damage_, Human *owner_) : damage(damage_), owner(owner_) { /*  */ }
	double weaponDMG() { return damage; }
};

class Human
{
public:
	double health;
	string Name;
	Weapon *weapon;
public:
	// Constructor with parameters
	Human(string name, Game *game);
	~Human()				{ delete weapon;	  }
	bool isAlive()			{ return getHP() > 0; }
	const string &getName() { return Name;		  }
	double getHP()			{ return health;	  }
	void dropWeapon()		{ /*  */ }

	bool hasWeapon()
	{
		if (weapon == nullptr) { return false; }
		else				   { return true;  }
	}

	virtual double inflictDMG(double damage)
	{
		health -= damage;
		return damage;
	}

	HitResult hit(Human *unit)
	{
		if (!isAlive() || !unit->isAlive())
		{
			cout << "Oops, you're dead already" << endl;
			return HitResult::Suicide;
		}
		if (!hasWeapon())
		{
			cout << "Oops, you don't have weapon, it would be nice to find her first!" << endl;
			return HitResult::Incorrect;
		}
		double damageDone = unit->inflictDMG(weapon->weaponDMG());
		if (!unit->isAlive())
		{
			cout << unit->getName() << " was killed!" << endl;
			return HitResult::Killed;
		}
		if (damageDone <= 0)
		{
			cout << unit->getName() << " missed!" << endl;
			return HitResult::Missed;
		}
		else
		{
			cout << fixed << setprecision(1);
			cout << unit->getName() << " got " << damageDone << " damage." << endl
				 << "Left " << unit->getHP() << " HP" << endl;
			return HitResult::Wounded;
		}
	}

	virtual void battleLog() { }

	virtual void action(Human *unit)
	{
		if (hit(unit) == HitResult::Killed)
		{
			cout << getName() << " wins!" << endl;
		}
	}

	virtual void information()
	{
		cout << fixed << setprecision(1);
		cout << endl << "#" << getName() << endl;
		cout << "Weapon: ";
		cout << (hasWeapon() ? "True - " : " False - ");
		cout << weapon->weaponDMG() << "DMG" << endl;
		cout << getHP() << "HP " << endl;
	}
};

class Warrior : public Human
{
public:
	double armor;
public:
	// Constructor with parameters
	Warrior(string Name, Game *game) : Human(Name, game), armor(0.2F) { /*  */ }

	double getArmor() { return armor; }

	double inflictDMG(double damage)
	{
		double resist = damage * armor;
		damage -= resist;
		this->health -= damage;
		return damage;
	}

	void information()
	{
		Human::information();
		cout << getArmor() << "Armor" << endl;
	}
};

class Mage : public Human
{
public:
	double mana;
public:
	// Constructor with parameters
	Mage(string Name, Game *game) : Human(Name, game), mana(100.0F) { /*  */ }

	double getMana() { return mana; }

	void information()
	{
		Human::information();
		cout << getMana() << "Mana" << endl;
	}
};

class Priest : public Mage
{
public:
	double heal;
public:
	// Constructor with parameters
	Priest(string Name, Game *game) : Mage(Name, game), heal(30.0F) { /*  */ }

	double getHeal() { return heal; }

	HitResult healing()
	{
		health += heal;
		mana -= 100;
		battleLog();
		return HitResult::Heal;
	}

	void action(Human *unit)
	{
		if (health <= 30 && mana >= 100)
		{
			healing();
		}
		else
		{
			Human::action(unit);
		}
	}

	void battleLog()
	{
		cout << getName() << " heal himself for"
			 << " - " << getHeal() << "HP" << endl
			 << "Left " << getMana() << " Mana" << endl;
	}

	void information()
	{
		Mage::information();
	}
};

class Game
{
public:
	mt19937 gen;
	uniform_real_distribution<> urd;

	Game() : gen(time(nullptr)), urd(15, 35) { /*  */ }
	double _randomize() { return urd(gen); }

	//template<typename T, typename F>
	void pvp(Human *unit1, Human *unit2)
	{
		while (unit1->isAlive() && unit2->isAlive()
			/*|| !unit1->isAlive() && !unit2->isAlive()*/)
		{
			if (unit1->isAlive())
			{
				unit1->action(unit2);
			}
			if (unit2->isAlive())
			{
				unit2->action(unit1);
			}
		}
	}

	void Play()
	{
		Mage *mage = new Mage("Mage1", this);
		Warrior *warrior = new Warrior("Warrior1", this);
		Priest *priest = new Priest("Priest1", this);

		pvp(mage, priest);
		cout << "///////////////Stats of characters///////////////";
		mage->information();
		priest->information();
	}
};

Human::Human(string name, Game *game) : Name(name), health(100.0F)
{
	weapon = new Weapon(game->_randomize(), this);
}
/*
implementation
*/
int main()
{
	Game *game = new Game;
	game->Play();


	return 0;
}