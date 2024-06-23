#include "NextLevelWindow.h"

NextLevelWindow::NextLevelWindow(Controller& controller)
	: m_controller(controller)
{
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));
	setButtons(controller);
}

void NextLevelWindow::handleEvent(const sf::Event& event, sf::RenderWindow& window, sf::Time time)
{
	//for (auto& button : m_buttons)
	//{
	//	button.execute(event);
	//}
}

void NextLevelWindow::draw(sf::RenderWindow& window, int r, int g, int b)
{
	m_background.setFillColor(sf::Color(r, g, b));
	window.draw(m_background);
	//for (auto& button : m_buttons)
	//{
	//	button.draw(window);
	//}
}

void NextLevelWindow::setButtons(Controller& controller)
{
	m_buttons.push_back(Button(sf::Vector2f(300, 500), sf::Vector2f(100, 50), BACK_TO_MENU, &m_resources.getBackButtonTexture(0), 
		std::move(std::make_unique<NextStateCommand>(controller, )))
}
