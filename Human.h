#ifndef __HUMAN_H__
#define __HUMAN_H__
#include <string>
#include <random> 
#include <ctime>
#include <iomanip>
#include <iostream>
///////////////////////////////////////////////////////////
class Game;
class Team;
class Weapon;
enum class HitResult;
using std::string;
using std::fixed;
using std::setprecision;
using std::cout;
using std::endl;
///////////////////////////////////////////////////////////
class Human
{
private:
	double health = 0.0F;
	string Name;
	Weapon *weapon = nullptr;
	Team *team = nullptr;
public:
	Human(string name, double from, double to, Team *team);
	~Human();
	bool isAlive();
	bool hasWeapon();
	void dropWeapon();
	void getTeamName();
	Team *getTeam();
	Weapon *getWeapon();
	double getHP();
	const string &getName();
	HitResult hit(Human *unit);
	virtual void battleLog();
	virtual void action(Human *unit);
	virtual void information();
	virtual void initWeapon();
	virtual double inflictDMG(double damage);
	virtual double heal(double _heal, Human *unit);
};

#endif // __HUMAN_H__