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

	std::cout << typeid(m_player).name() << "\n";
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
	if (event.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//JUMP!!!
	}

	return nullptr;
}

void Game::draw(sf::RenderWindow& window)
{

	sf::View originalView = window.getView();

	_view.setCenter(m_player.getPosition().x, m_player.getPosition().y);
	window.setView(_view);

	for (Object& obj : m_movables)
	{
		obj.draw(window);
	}
	for (Object& obj : m_fixed)
	{
		obj.draw(window);
	}


	m_player.draw(window);

	window.setView(window.getDefaultView());
	//here we will draw anything thats not supposed to move on screen
	m_pauseButton->draw(window);

	// Restore the original view
	window.setView(originalView);
}

void Game::update(sf::Time time)
{
	auto dt = time.asSeconds();
	puts("s");
	m_world->Step(TIME_STEP, 6, 2); 

	m_player.updatePos(time);										
}

void Game::setChosenPlayer(int i)
{
	m_player.setChosenPlayer(i);
}

void Game::setState(Menu* menu)
{
	m_menuState = menu;
}

void Game::initPlayer()
{
	m_player.setPosition(m_map.getPlayerLocation());
	m_player.setBox(m_world);
	m_player.setSize(59, 59);
}

void Game::initWorld()
{
	_view = sf::View(sf::FloatRect(300, 300, WINDOW_X / 0.5, WINDOW_Y / 0.5));
	m_world = std::make_unique<b2World>(m_gravity);
	
	m_world->SetContactListener(&m_listner);
	
	m_map.setWorld(m_level, m_world, m_movables, m_fixed);

	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground());
}
