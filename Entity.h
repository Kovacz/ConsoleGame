#pragma once
#include <SFML/Graphics.hpp>
///////////////////////////////////////////////////////////
class Entity
{
private:
	float x, y, frame, speed, angle;
	unsigned width, height;
	bool isMove;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Entity(sf::Image &image, float dx, float dy, int w, int h);
	~Entity();
	const sf::FloatRect getRect();
	const float getFrame();
	const float getSpeed();
	const float getAngle();
	const unsigned getWidth();
	const unsigned getHeight();
	const bool getIsMove();
	virtual void animation(float &time, sf::Vector2f &totalMovement, int scale) = 0;
	virtual void interactionWithMap(const sf::Rect<float> &rect) = 0;
};
