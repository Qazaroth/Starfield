#include "Star.h"

// Private
void Star::setup()
{
	float x = _windowSize.x;
	float y = _windowSize.y;
	this->x = Utils::getRandomNumber(-x/2, x/2);
	this->y = Utils::getRandomNumber(-y/2, y/2);
	this->z = Utils::getRandomNumber(0, x);
	this->pz = this->z;
}
// Public
Star::Star(sf::Vector2u windowSize) : _windowSize(windowSize)
{
	setup();
}

Star::~Star() {}

void Star::update(float speed)
{
	z = z - speed;
	float x = _windowSize.x;
	float y = _windowSize.y;

	if (z < 1)
	{
		this->x = Utils::getRandomNumber(-x / 2, x / 2);
		this->y = Utils::getRandomNumber(-y / 2, y / 2);
		this->z = x;
		this->pz = this->z;
	}
}

void Star::show(sf::RenderWindow &window)
{
	_windowSize = window.getSize();

	//sprite.setOrigin(window.getSize().x / 2, window.getSize().y / 2);
	sprite.setFillColor(sf::Color::White);
	sprite.setOutlineThickness(0);

	float sx = Utils::map(x / z, 0, 1, 0, _windowSize.x);
	float sy = Utils::map(y / z, 0, 1, 0, _windowSize.y);
	float r = Utils::map(z, 0, _windowSize.x, 8, 0);

	//std::cout << z << std::endl;
	sprite.setRadius(r);
	sprite.setOrigin(r/2, r/2);
	sprite.setPosition(sx, sy);

	float px = Utils::map(x / pz, 0, 1, 0, _windowSize.x);
	float py = Utils::map(y / pz, 0, 1, 0, _windowSize.y);

	//window.draw(sprite);
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(sx, sy)),
		sf::Vertex(sf::Vector2f(px, py))
	};
	window.draw(line, 2, sf::Lines);

	this->pz = this->z;
}