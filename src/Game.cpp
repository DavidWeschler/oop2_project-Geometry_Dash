#include "Game.h"
#include <iostream>

Game::Game(int levelNum)
	:m_map(levelNum)
	//: m_pauseButton(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 64, WINDOW_X / 64), RETURN, &m_cir, &m_resources.getBackButtonTexture(1))
{
	m_pauseButton.push_back(Button(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 64, WINDOW_X / 64), RETURN, &m_cir, &m_resources.getBackButtonTexture(2)));
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground());
	m_level = levelNum;
	m_map.setWorld(m_level);
}

GameState* Game::handleEvent(const sf::Event& event, sf::RenderWindow&window)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (m_pauseButton[0].getGlobalBound().contains(event.mouseButton.x, event.mouseButton.y)) //not pause button!!!!!
		{
			return m_menuState;
		}
		break;
	}
	return nullptr;
}

void Game::draw(sf::RenderWindow& window)
{
	sf::View view(sf::FloatRect(300,300, WINDOW_X/3, WINDOW_Y/3));
	window.setView(view);
	view.setCenter(400, 400);
	window.setView(view);


	window.clear();
	window.draw(m_background);
	m_map.drawWold(window);
	m_pauseButton[0].draw(window);
}

void Game::setState(Menu* menu)
{
	m_menuState = menu;
}
