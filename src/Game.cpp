#include "Game.h"
#include <iostream>
#include <ranges>

Game::Game(int levelNum)
	:m_map(levelNum), m_gravity(GRAVITY_X, GRAVITY_Y)
{
	m_level = levelNum;
	initWorld();
	m_pauseButton= std::make_unique<Button>(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 64, WINDOW_X / 64), RETURN, &m_cir, &m_resources.getBackButtonTexture(2));
	m_startLocation = m_map.getPlayerLocation();
	initPlayer();

	std::cout << m_movables.size() << " " << m_fixed.size() << std::endl;
}

GameState* Game::handleEvent(const sf::Event& event, sf::RenderWindow&window, sf::Time time)
{
	auto dt = time.asSeconds();
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (m_pauseButton->getGlobalBound().contains(event.mouseButton.x, event.mouseButton.y)) //not pause button!!!!!
		{
			return m_menuState;
		}
		break;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_player->startJump();
	}

	return nullptr;
}

void Game::draw(sf::RenderWindow& window)
{

	sf::View originalView = window.getView();

	_view.setCenter(m_player->getPosition().x, m_player->getPosition().y);
	window.setView(_view);

	for (auto obj = m_movables.begin(); obj != m_movables.end(); obj++)
	{
		(*obj)->draw(window);
	}

	for (auto obj = m_fixed.begin(); obj != m_fixed.end(); obj++)
	{
		(*obj)->draw(window);
	}


	m_player->draw(window);

	window.setView(window.getDefaultView());
	//here we will draw anything thats not supposed to move on screen
	m_pauseButton->draw(window);

	// Restore the original view
	window.setView(originalView);
}

void Game::update(sf::Time time)
{
	auto dt = time.asSeconds();

	m_world->Step(TIME_STEP, 6, 2); 

	m_player->updatePos(time);										
}

void Game::setChosenPlayer(int i)
{
	m_player->setChosenPlayer(i);
}

void Game::setState(Menu* menu)
{
	m_menuState = menu;
}

void Game::initPlayer()
{
	m_player = std::make_unique<Player>(m_world, m_resources.getPlayerTexture(0), sf::Color::Red, m_startLocation);
	m_player->setSize(59, 59);
}

void Game::initWorld()
{
	_view = sf::View(sf::FloatRect(300, 300, WINDOW_X / 1.2, WINDOW_Y / 1.2));
	m_world = std::make_unique<b2World>(m_gravity);
	m_map.setWorld(m_level, m_world, m_movables, m_fixed);
	
	m_world->SetContactListener(&m_listner);

	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground());
}
