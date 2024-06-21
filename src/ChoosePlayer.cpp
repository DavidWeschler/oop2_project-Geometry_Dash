#include "ChoosePlayer.h"
#include "Controller.h"
#include "Menu.h"

#include <iostream>

ChoosePlayer::ChoosePlayer(Controller& controller)
{
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));

	m_backgroundText.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_backgroundText.setTexture(&m_resources.getMenuBackground(2));

	//m_exitButton = std::make_unique<Button>(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), 
	//	sf::Vector2f(WINDOW_X / 32, WINDOW_X / 32), 
	//	RETURN, 
	//	&m_resources.getBackButtonTexture(1),
	//	std::move(std::make_unique<NextStateCommand>(controller, m_menuState)));

	setButtons(controller);
}

void ChoosePlayer::setButtons(Controller& controller)
{
	for (int i = 0; i <5; i++)
	{
		m_setsButtons.push_back(Button(sf::Vector2f(i*263 + WINDOW_X * 1 / 6, WINDOW_Y *4/ 12), 
			sf::Vector2f(WINDOW_X / 7, WINDOW_X / 14),
			m_resources.getSetsNames(i),
			&m_resources.getSetButtonTexture(i),
			std::move(std::make_unique<ChoosePlayerCommand>(*m_menuState, controller, i))));		//texture needs to change
	}
	for (int i = 5; i < 10; i++)
	{
		m_setsButtons.push_back(Button(sf::Vector2f((i-5) * 263 + WINDOW_X * 1 / 6, WINDOW_Y*6 / 12), 
			sf::Vector2f(WINDOW_X / 7, WINDOW_X / 14), 
			m_resources.getSetsNames(i), 
			&m_resources.getSetButtonTexture(i),
			std::move(std::make_unique<ChoosePlayerCommand>(*m_menuState, controller, i))));		//same
	}
	for (int i = 10; i < NUM_OF_CHOOSE_SETS; i++)
	{
		m_setsButtons.push_back(Button(sf::Vector2f((i - 10) * 263 + WINDOW_X * 1 / 6, WINDOW_Y * 8 / 12), 
			sf::Vector2f(WINDOW_X / 7, WINDOW_X / 14), 
			m_resources.getSetsNames(i), 
			&m_resources.getSetButtonTexture(i),
			std::move(std::make_unique<ChoosePlayerCommand>(*m_menuState, controller, i))));		//same
	}

	//outline for sets
	for (int i = 0; i < NUM_OF_CHOOSE_SETS; i++)
	{
		m_setsButtons[i].setOutlineThickness(3.f);
		m_setsButtons[i].setOutlineColor(sf::Color::Black);
	}
}

//void ChoosePlayer::markChoice(sf::RenderWindow& window)
//{
//	m_exitButton[0].getGlobalBound().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) ?
//											m_exitButton[0].setScale(1.1f, 1.1f) : m_exitButton[0].setScale(1.0f, 1.0f);
//	for (int i = 0; i < NUM_OF_CHOOSE_SETS; i++)
//	{
//		m_setsButtons[i].getGlobalBound().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) ?
//													m_setsButtons[i].setScale(1.1f, 1.1f) : m_setsButtons[i].setScale(1.0f, 1.0f);
//	}
//}

void ChoosePlayer::handleEvent(const sf::Event& event, sf::RenderWindow& window, sf::Time time)
{
	for (auto& button : m_setsButtons)
	{
		button.execute(event);
	}
	m_exitButton->execute(event);
}

//void ChoosePlayer::handleChoice(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
//{
//	markChoice(window);	//return here an index
//
//	//get rid of this loop and use the index from above
//	for (int i = 0; i < NUM_OF_CHOOSE_SETS; i++)
//	{
//		if (m_setsButtons[i].getGlobalBound().contains(event.x, event.y))
//		{
//			m_menuState->setChosenPlayer(i);
//		}
//	}
//}

void ChoosePlayer::draw(sf::RenderWindow& window, int r, int g, int b)
{
	window.clear();
	m_background.setFillColor(sf::Color(r,g,b));
	window.draw(m_background);
	window.draw(m_backgroundText);
	m_exitButton->draw(window);
	for (auto i = 0; i < m_setsButtons.size(); i++)
	{
		m_setsButtons[i].draw(window);
	}
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
		RETURN,
		&m_resources.getBackButtonTexture(1),
		std::move(std::make_unique<NextStateCommand>(controller, *m_menuState)));
}