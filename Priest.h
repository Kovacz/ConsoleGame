#ifndef __PRIEST_H__
#define __PRIEST_H__

class Priest : public Mage
{
public:
	double heal;
public:
	Priest(string Name, Game *game);
	double getHeal();
	HitResult healing();
	void action(Human *unit);
	void battleLog();
	void information();
};

#endif // __PRIEST_H__