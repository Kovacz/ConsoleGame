#ifndef __HUMAN_H__
#define __HUMAN_H__

class Human
{
public:
	double health;
	string Name;
	Weapon *weapon;
public:
	Human(string name, Game *game);
	~Human();
	bool isAlive();
	const string &getName();
	double getHP();
	void dropWeapon();
	bool hasWeapon();
	HitResult hit(Human *unit);
	virtual double inflictDMG(double damage);
	virtual void battleLog();
	virtual void action(Human *unit);
	virtual void information();
};

#endif // __HUMAN_H__