#include "ScreenStates/Statistics.h"
#include <Windows.h>

Statistics::Statistics(Controller& controller)
	: m_controller(controller)
{
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));
	setButtons(controller);
}

void Statistics::handleEvent(const sf::Event& event, sf::RenderWindow& window, sf::Time time)
{
	//these function happens in every screenstate! move up in the tree!
	for (auto& button : m_buttons)
	{
		button.execute(event);
	}
	for (int i = 0; i < m_buttons.size(); i++)
	{
		if (m_buttons[i].getGlobalBound().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		{
			m_buttons[i].setScale(1.1f, 1.1f);
		}
		else {
			m_buttons[i].setScale(1.0f, 1.0f);
		}
	}
}

void Statistics::draw(sf::RenderWindow& window, int r, int g, int b)
{
	m_background.setFillColor(sf::Color(r, g, b));
	window.draw(m_background);
	for (auto& button : m_buttons)
	{
		button.draw(window);
	}
}

void Statistics::setButtons(Controller& controller)
{
	//return button
	m_buttons.push_back(Button(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 32, WINDOW_X / 32), BACK_TO_MENU, &m_resources.getBackButtonTexture(1), std::move(std::make_unique<NextStateCommand>(controller, GameStates::MENU_S))));
}