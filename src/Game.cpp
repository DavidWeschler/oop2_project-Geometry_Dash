#include "Game.h"
#include <iostream>
#include <ranges>

Game::Game(int levelNum)
	:m_map(levelNum), m_gravity(GRAVITY_X, GRAVITY_Y)
{
	m_level = levelNum;
	initWorld();
	m_pauseButton= std::make_unique<Button>(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 32, WINDOW_X / 32), RETURN, &m_resources.getBackButtonTexture(2));
	m_startLocation = m_map.getPlayerLocation();
	initPlayer();

	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_player->setJumping(true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		m_world->SetGravity(b2Vec2(GRAVITY_X, GRAVITY_Y));
		m_player->setState(PlayerState::FORWARD_S);
		m_player->changeState(m_world);
		m_player->setSpiked(true);
	}

	return nullptr;
}

void Game::draw(sf::RenderWindow& window, int r, int g, int b)
{
	static int counter = 0;
	static int axisY = m_player->getPosition().y - 220;
	window.clear();
	m_background.setFillColor(sf::Color(r, g, b));
	window.draw(m_background);

	sf::View originalView = window.getView();

	if (m_player->getStateType() == PlayerState::UPSIDEDOWN_S)
	{
		if (counter < 200)
			counter++;
	}
	else
	{
		if (counter > -200)
			counter--;
	}
	_view.setCenter(m_player->getPosition().x + 300, m_player->getPosition().y + counter);
	window.setView(_view);

	for (auto obj = m_movables.begin(); obj != m_movables.end(); obj++)
	{
		(*obj)->draw(window);
	}

	for (auto obj = m_fixed.begin(); obj != m_fixed.end(); obj++)
	{
		auto d_ox = (*obj)->getPosition().x;
		auto d_px = m_player->getPosition().x;
		auto d_oy = (*obj)->getPosition().y;
		auto d_py = m_player->getPosition().y;
		
		if (std::abs(d_ox - d_px) < 1250 && std::abs(d_oy - d_py) < 700.0f)// &&  d_ox > (d_px-550))
		{
			(*obj)->draw(window);
		}
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
	while (dt > 0.0f)
	{
		float ts = std::min(dt, 1.0f / 60.0f);
		m_world->Step(ts, 6, 2);
		dt -= ts;
	}

	m_player->changeState(m_world);
	m_player->move(time);
	moveEnemy(time);
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
	m_player = std::make_unique<Player>(m_world, m_startLocation);
	m_player->setSize(61, 61);
}

void Game::initWorld()
{
	_view = sf::View(sf::FloatRect(300, 300, WINDOW_X/0.9, WINDOW_Y/0.9));
	m_world = std::make_unique<b2World>(m_gravity);
	m_map.setWorld(m_level, m_world, m_movables, m_fixed);
	
	m_world->SetContactListener(&m_listner);

	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));
}

void Game::moveEnemy(sf::Time time)
{
	for (auto& enemy : m_movables)
	{
		enemy->move(time);
	}
}
