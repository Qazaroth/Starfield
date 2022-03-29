#include <iostream>

#include <SFML\Graphics.hpp>

#include "Star.h"
#include "FPSTimer.h"
#include "Utils.h"

#define DEBUGGING

std::string TITLE = "Starfield in C++";
sf::Uint32 styleFlag = sf::Style::Default;

FPSTimer timer;
float timerCounter = 0;
unsigned int frames = 0;

sf::RectangleShape rect(sf::Vector2f(15, 15));

const int MAX_STARS = 200;

Star stars[MAX_STARS];
//Star star(window.getSize());

void resizeHandler(sf::Event e, sf::RenderWindow &window)
{
	window.setSize(sf::Vector2u(e.size.width, e.size.height));
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), TITLE, styleFlag);
	sf::Vector2u size = window.getSize();
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(size.x, size.y));
	
	int starsSize = sizeof(stars) / sizeof(Star);

	for (int i = 0; i < starsSize; i++)
	{
		stars[i] = Star(window.getSize());
	}
	
	//std::cout << sizeof(stars)/sizeof(Star) << std::endl;
	//float widthHalf = window.getSize().x / 2;
	//float heightHalf = window.getSize().y / 2;
	//view.move(sf::Vector2f(-widthHalf, -heightHalf));

	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Red);

	window.setView(view);

	while (window.isOpen())
	{
		starsSize = sizeof(stars) / sizeof(Star);

		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Event windowEvent;

		float speed = Utils::map(mousePosition.x, -60, window.getSize().x, 0, 20);

		window.clear(sf::Color::Black);
		//window.draw(rect);
		for (int i = 0; i < starsSize; i++)
		{
			stars[i].update(speed);
			stars[i].show(window);
		}
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

		frames++;
		if (timer.elapsed() - timerCounter > 1.0f)
		{
			timerCounter += 1.0f;
			printf("%d FPS\n", frames);
			frames = 0;
		}
	}

	return 0;
}