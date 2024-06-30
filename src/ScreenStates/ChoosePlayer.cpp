#include "ScreenStates/ChoosePlayer.h"
#include "ScreenStates/Controller.h"
#include "ScreenStates/Menu.h"

ChoosePlayer::ChoosePlayer(Controller& controller)
{
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));
	m_backgroundText.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_backgroundText.setTexture(&m_resources.getMenuBackground(2));
	setButtons(controller);
}

void ChoosePlayer::setButtons(Controller& controller)
{
	for (int i = 0; i <5; i++)
	{
		m_setsButtons.push_back(Button(sf::Vector2f(i*263 + WINDOW_X * 1 / 6, WINDOW_Y *4/ 12), 
			sf::Vector2f(WINDOW_X / 7, WINDOW_X / 14),
			&m_resources.getSetButtonTexture(i),
			std::move(std::make_unique<ChoosePlayerCommand>(*m_menuState, controller, i))));
	}
	for (int i = 5; i < 10; i++)
	{
		m_setsButtons.push_back(Button(sf::Vector2f((i-5) * 263 + WINDOW_X * 1 / 6, WINDOW_Y*6 / 12), 
			sf::Vector2f(WINDOW_X / 7, WINDOW_X / 14),  
			&m_resources.getSetButtonTexture(i),
			std::move(std::make_unique<ChoosePlayerCommand>(*m_menuState, controller, i))));
	}
	for (int i = 10; i < NUM_OF_CHOOSE_SETS; i++)
	{
		m_setsButtons.push_back(Button(sf::Vector2f((i - 10) * 263 + WINDOW_X * 1 / 6, WINDOW_Y * 8 / 12), 
			sf::Vector2f(WINDOW_X / 7, WINDOW_X / 14),  
			&m_resources.getSetButtonTexture(i),
			std::move(std::make_unique<ChoosePlayerCommand>(*m_menuState, controller, i))));
	}

	for (int i = 0; i < NUM_OF_CHOOSE_SETS; i++)
	{
		m_setsButtons[i].setOutlineThickness(3.f);
		m_setsButtons[i].setOutlineColor(sf::Color::Black);
	}
}

void ChoosePlayer::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	for (auto& button : m_setsButtons) button.execute(event);
	m_exitButton->execute(event);
}

void ChoosePlayer::draw(sf::RenderWindow& window, int r, int g, int b)
{
	m_background.setFillColor(sf::Color(r,g,b));
	window.draw(m_background);
	window.draw(m_backgroundText);
	m_exitButton->draw(window);

	for (auto& button : m_setsButtons) button.draw(window);
}

void ChoosePlayer::setStates(Menu* menu)
{
	m_menuState = menu;
}

void ChoosePlayer::setExitButton(Controller& controller)
{
	m_exitButton = std::make_unique<Button>(
		sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30),
		sf::Vector2f(WINDOW_X / 32, WINDOW_X / 32),
		&m_resources.getBackButtonTexture(1),
		std::move(std::make_unique<NextStateCommand>(controller, GameStates::MENU_S)));
}