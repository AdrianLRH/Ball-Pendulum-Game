/*!
@file main.cpp
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game.h"

void main()
{
	//! Creating window and world size
	sf::RenderWindow window(sf::VideoMode(800, 600), "Balls and Pendulums");

	sf::Vector2f worldSize(8.0f, 6.0f);

	sf::Clock timer;

	Game game;

	//! Creating game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			//! Key input
			if (event.type == sf::Event::KeyPressed)
			{
				game.keyPress(event.key.code);
			}
			//! Mouse input
			if (event.type == sf::Event::MouseButtonPressed) 
			{
				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					game.mouseClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
				}
			}
		}


		float elapsed = timer.getElapsedTime().asSeconds();

		if (elapsed >= 1.0 / 30.0)
		{
			game.update(elapsed); //!< updating screen, calling function from 'Game' class
			timer.restart();
		}

		window.clear(sf::Color::Cyan);
		window.draw(game);
		window.display();
	}
}