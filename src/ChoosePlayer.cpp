#include "ChoosePlayer.h"

ChoosePlayer::ChoosePlayer()
{
}

void ChoosePlayer::go(sf::RenderWindow& window)
{
	while (m_window->isOpen())
	{
		m_window->clear(sf::Color::Yellow);
		//draw();
		m_window->display();

		sf::Event event;
		while (m_window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				//handleClick(event.mouseButton);
				break;
			}
		}
	}
}
