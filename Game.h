#pragma once
///////////////////////////////////////////////////////////
#include <random> 
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cmath>
///////////////////////////////////////////////////////////
class Human;
///////////////////////////////////////////////////////////
class Game
{
private:
	std::mt19937 gen;
	std::uniform_real_distribution<> urd;
public:
	void Play();
	static Game &Instance();
	unsigned _randomize(const unsigned &from, const unsigned &to);
	double _randomize(std::uniform_real_distribution<> urd);
private:
	Game();
	~Game();
	Game(Game const&) = delete;
	Game &operator=(Game const&) = delete;
};