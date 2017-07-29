#ifndef __GAME_H__
#define __GAME_H__

#include <random> 
#include <ctime>
class Human;

using std::string;

class Game
{
public:
	std::mt19937 gen;
	std::uniform_real_distribution<> urd;
public:
	Game();
	double _randomize();
	void pvp(Human *unit1, Human *unit2);
	void Play();
};

#endif // __GAME_H__