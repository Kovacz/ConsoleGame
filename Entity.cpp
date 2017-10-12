#include "Entity.h"

Entity::Entity(sf::Image &image, float dx, float dy, int w, int h) : x(dx), y(dy), width(w), height(h), frame(0.f), speed(7.f), isMove(false)
{
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(dx, dy);
	sprite.setTextureRect(sf::IntRect(500, 750, w, h));
}

Entity::~Entity()
{
	/*...*/
}

const sf::FloatRect Entity::getRect()
{
	return sf::FloatRect(x, y, (float)width, (float)height);
}

const float Entity::getFrame() 
{
	return frame;
}

const float Entity::getSpeed()
{
	return speed;
}

const float Entity::getAngle()
{
	return angle;
}
const unsigned Entity::getWidth()
{
	return width;
}

const unsigned Entity::getHeight()
{
	return height;
}

const bool Entity::getIsMove()
{
	return isMove;
}

