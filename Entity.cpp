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

float Entity::getFrame() const
{
	return frame;
}

float Entity::getSpeed() const
{
	return speed;
}

float Entity::getAngle() const
{
	return angle;
}
unsigned Entity::getWidth() const
{
	return width;
}

unsigned Entity::getHeight() const
{
	return height;
}

bool Entity::getIsMove() const
{
	return isMove;
}

