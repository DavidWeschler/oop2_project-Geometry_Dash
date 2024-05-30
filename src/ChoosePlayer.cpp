#include "ChoosePlayer.h"

ChoosePlayer::ChoosePlayer(Menu& menu)
	: m_menuState(menu)
{
	m_exitButton.push_back(Button(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 64, WINDOW_X / 64), RETURN, &m_cir));
	setButtons();
}


void ChoosePlayer::setButtons()
{
	for (int i = 0; i <5; i++)
	{
		m_setsButtons.push_back(Button(sf::Vector2f(i*100 + WINDOW_X * 1 / 4, WINDOW_Y / 4), sf::Vector2f(WINDOW_X / 20, WINDOW_X / 30), DEFAULT, &m_rec[i]));
	}
	for (int i = 6; i < NUM_OF_CHOOSE_SETS; i++)
	{
		m_setsButtons.push_back(Button(sf::Vector2f(i-6 * 100 + WINDOW_X * 1 / 4, WINDOW_Y *2/ 4), sf::Vector2f(WINDOW_X / 20, WINDOW_X / 30), DEFAULT, &m_rec[i]));
	}
}

void ChoosePlayer::go(sf::RenderWindow& window)
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
			return &m_menuState;
		}
		handleChoice(event.mouseButton, window);
	}
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (event.key.code == sf::Keyboard::Escape)
			return &m_menuState;
	}
	return nullptr;
}

void ChoosePlayer::handleChoice(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	for (int i = 0; i < NUM_OF_CHOOSE_SETS; i++)
	{
		if (m_setsButtons[i].getGlobalBound().contains(event.x, event.y))
		{
			/*if (m_setsButtons[i].getType() == RETURN) {
				puts("pressed");
			}*/
		}
	}
}

void ChoosePlayer::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color(230, 194, 73));
	m_exitButton[0].draw(window);
	for (auto i = 0; i < m_setsButtons.size()-1; i++)
	{
		m_setsButtons[i].draw(window);
	}
}