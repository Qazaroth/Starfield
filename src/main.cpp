#include <iostream>

#include <SFML\Graphics.hpp>

#include "Star.h"

#define DEBUGGING

std::string TITLE = "Starfield in C++";
sf::Uint32 styleFlag = sf::Style::Default;

void resizeHandler(sf::Event e, sf::RenderWindow &window)
{
	window.setSize(sf::Vector2u(e.size.width, e.size.height));
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), TITLE, styleFlag);

	Star star(window.getSize());

	while (window.isOpen())
	{
		sf::Event windowEvent;

		window.clear(sf::Color::Black);
		window.display();

		while (window.pollEvent(windowEvent))
		{
			switch (windowEvent.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				resizeHandler(windowEvent, window);
				break;
			default:
				break;
			}
		}
	}

	return 0;
}