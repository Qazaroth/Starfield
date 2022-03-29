#include "Star.h"

Star::Star(sf::Vector2u windowSize) : _windowSize(windowSize)
{
	this->x = Utils::getRandomNumber(0, windowSize.x);
	this->y = Utils::getRandomNumber(0, windowSize.y);
	this->z = Utils::getRandomNumber(0, windowSize.x);
}

Star::~Star() {}