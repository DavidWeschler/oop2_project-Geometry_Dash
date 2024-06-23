#include "ScreenStates/NextLevelWindow.h"

NextLevelWindow::NextLevelWindow(Controller& controller)
	: m_controller(controller)
{
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));
	setButtons(controller);
}

void NextLevelWindow::handleEvent(const sf::Event& event, sf::RenderWindow& window, sf::Time time)
{
	for (auto& button : m_buttons)
	{
		button.execute(event);
	}

	for (int i = 0; i < 2; i++)
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

void NextLevelWindow::draw(sf::RenderWindow& window, int r, int g, int b)
{
	m_background.setFillColor(sf::Color(r, g, b));
	window.draw(m_background);
	for (auto& button : m_buttons)
	{
		button.draw(window);
	}
}

void NextLevelWindow::setButtons(Controller& controller)
{
	m_buttons.push_back(Button(sf::Vector2f(300, 500), sf::Vector2f(150, 150), BACK_TO_MENU, &m_resources.getMenuButtonTexture(5),//5
		std::move(std::make_unique<NextStateCommand>(controller, GameStates::MENU_S))));

	m_buttons.push_back(Button(sf::Vector2f(800, 500), sf::Vector2f(150, 150), NEW_GAME, &m_resources.getMenuButtonTexture(6),//6
		std::move(std::make_unique<NextStateCommand>(controller, GameStates::GAME_S))));
}
