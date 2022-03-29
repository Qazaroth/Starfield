#pragma once

#include <SFML\Graphics.hpp>

#include "Utils.h"

class Star
{
private:
	float x, y;
	float z;

	float pz;

	sf::CircleShape sprite;

	sf::Vector2u _windowSize;

	void setup();
public:
	Star() {}
	Star(sf::Vector2u windowSize);
	~Star();

	void update(float speed);
	void show(sf::RenderWindow &window);
};