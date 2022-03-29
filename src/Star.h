#pragma once

#include <SFML\Graphics.hpp>

#include "Utils.h"

class Star
{
private:
	float x;
	float y;
	float z;

	sf::Vector2u _windowSize;
public:
	Star(sf::Vector2u windowSize);
	~Star();
};