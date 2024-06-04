#include "ChoosePlayer.h"

#include <iostream>

ChoosePlayer::ChoosePlayer()
{
	m_exitButton.push_back(Button(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 64, WINDOW_X / 64), RETURN, &m_cir, &m_resources.getBackButtonTexture(1)));
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground());
	setButtons();
}

void ChoosePlayer::setButtons()
{
	for (int i = 0; i <5; i++)
	{
		m_setsButtons.push_back(Button(sf::Vector2f(i*263 + WINDOW_X * 1 / 6, WINDOW_Y *2/ 5), sf::Vector2f(WINDOW_X / 7, WINDOW_X / 14), m_resources.getSetsNames(i), &m_rec[i], &m_resources.getSetButtonTexture(i)));		//texture needs to change
		}
	for (int i = 5; i < NUM_OF_CHOOSE_SETS; i++)
	{
		m_setsButtons.push_back(Button(sf::Vector2f((i-5) * 263 + WINDOW_X * 1 / 6, WINDOW_Y*7 / 10), sf::Vector2f(WINDOW_X / 7, WINDOW_X / 14), m_resources.getSetsNames(i), &m_rec[i], &m_resources.getSetButtonTexture(i)));		//same
	}

	//outline for sets
	for (int i = 0; i < NUM_OF_CHOOSE_SETS; i++)
	{
		m_setsButtons[i].setOutlineThickness(3.f);
		m_setsButtons[i].setOutlineColor(sf::Color::Black);
	}
}

void ChoosePlayer::markChoice(sf::RenderWindow& window)
{
	m_exitButton[0].getGlobalBound().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) ?
											m_exitButton[0].setScale(1.1f, 1.1f) : m_exitButton[0].setScale(1.0f, 1.0f);
	for (int i = 0; i < NUM_OF_CHOOSE_SETS; i++)
	{
		m_setsButtons[i].getGlobalBound().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) ?
													m_setsButtons[i].setScale(1.1f, 1.1f) : m_setsButtons[i].setScale(1.0f, 1.0f);
	}
}

GameState* ChoosePlayer::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (m_exitButton[0].getGlobalBound().contains(event.mouseButton.x, event.mouseButton.y))
		{
			return m_menuState;
		}
		handleChoice(event.mouseButton, window);
	}
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (event.key.code == sf::Keyboard::Escape)
			return m_menuState;
	}
	return nullptr;
}

void ChoosePlayer::handleChoice(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{

	markChoice(window);	//return here an index

	//get rid of this loop and use the index from above
	for (int i = 0; i < NUM_OF_CHOOSE_SETS; i++)
	{
		if (m_setsButtons[i].getGlobalBound().contains(event.x, event.y))
		{
			m_menuState->setChosenPlayer(i);
		}
	}
}

void ChoosePlayer::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(m_background);
	m_exitButton[0].draw(window);
	for (auto i = 0; i < m_setsButtons.size(); i++)
	{
		m_setsButtons[i].draw(window);
	}
}

void ChoosePlayer::setStates(Menu* menu)
{
	m_menuState = menu;
}
