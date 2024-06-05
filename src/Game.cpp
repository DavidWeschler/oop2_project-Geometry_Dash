#include "Game.h"
#include <iostream>

Game::Game(int levelNum)
	:m_map(levelNum), m_gravity(GRAVITY_X, GRAVITY_X), m_world(m_gravity)
{
	//m_world.SetGravity(m_gravity)
	m_pauseButton.push_back(Button(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 64, WINDOW_X / 64), RETURN, &m_cir, &m_resources.getBackButtonTexture(2)));
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground());
	m_level = levelNum;
	m_map.setWorld(m_level, m_world);
	m_startLocation = m_map.getPlayerLocation();
	m_player.setPosition(m_map.getPlayerLocation());
	m_player.setSize(59, 59);
}

GameState* Game::handleEvent(const sf::Event& event, sf::RenderWindow&window, sf::Time time)
{
	auto dt = time.asSeconds();
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (m_pauseButton[0].getGlobalBound().contains(event.mouseButton.x, event.mouseButton.y)) //not pause button!!!!!
		{
			return m_menuState;
		}
		break;
	}
	if (event.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//JUMP!!!
	}

	m_player.updatePos();

	m_world.Step(dt, 10, 8);
	return nullptr;
}

void Game::draw(sf::RenderWindow& window)
{
	m_map.drawWold(window);
	m_player.draw(window);
	m_pauseButton[0].draw(window);
}

void Game::setChosenPlayer(int i)
{
	m_player.setChosenPlayer(i);
}

void Game::setState(Menu* menu)
{
	m_menuState = menu;
}
