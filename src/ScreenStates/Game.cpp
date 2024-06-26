#include "ScreenStates/Game.h"
#include <iostream>
#include <ranges>	//cgeck this
#include "ButtonCommand/NextStateCommand.h"
#include "ScreenStates/Controller.h"
#include "ScreenStates/Menu.h"
#include <ctime>
#include <algorithm> // Include for std::for_each

Game::Game(Controller& controller, Menu& menuState, sf::Music& music)
	:m_map(setLevelsOrder(), m_movables, m_fixed), m_gravity(GRAVITY_X, GRAVITY_Y), m_controller(controller),
	 m_backgroundMusic(music)
{
	initWorld();

	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));

	m_pauseButton= std::make_unique<Button>(
		sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), 
		sf::Vector2f(WINDOW_X / 32, WINDOW_X / 32), 
		RETURN, 
		&m_resources.getBackButtonTexture(2),
		std::move(std::make_unique<NextStateCommand>(controller, GameStates::MENU_S)));

	m_startLocation = m_map.getPlayerLocation();
	initPlayer();

	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));
}

int Game::setLevelsOrder()
{
	std::vector<int> levels = { 1 };
	std::default_random_engine randomize(std::time(nullptr));
	if (m_levelIndex.empty())
	{
		std::shuffle(levels.begin(), levels.end(), randomize);
		for (int num : levels) {
			m_levelIndex.push(num);
		}
	}
	m_level = m_levelIndex.front();
	return m_level;
}



void Game::handleEvent(const sf::Event& event, sf::RenderWindow&window, sf::Time time)
{
	auto dt = time.asSeconds();

	m_pauseButton->execute(event);

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		fireBullet();
	}
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

	for (auto& bullet : m_bullets)
	{
		bullet->draw(window);
	}
	//---------------------------

	for (auto obj = m_fixed.begin(); obj != m_fixed.end(); obj++)
	{
		auto d_ox = (*obj)->getPosition().x;
		auto d_px = m_player->getPosition().x;
		auto d_oy = (*obj)->getPosition().y;
		auto d_py = m_player->getPosition().y;
		
		if (std::abs(d_ox - d_px) < 1200 && std::abs(d_oy - d_py) < 750.0f)// &&  d_ox > (d_px-550))
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
	handleRestart();
	handleDeletionBullets();

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
	moveBullets(time);

	if (getReplaceMusic())
	{
		setSwitchMusic();
		setReplaceMusic(false);
	}
}

void Game::setChosenPlayer(int i)
{
	m_player->setChosenPlayer(i);
}

void Game::setState(Menu* menu)	//are we using this? - yes
{
	m_menuState = menu;
}

void Game::setUpLevel()
{
	m_level = setLevelsOrder();
}

void Game::setSwitchMusic()
{
	srand(std::time(NULL));
	int track = 2 + rand() % 8;

	sf::Music& newMusic = m_musicHandler.getMusicTrack(track);

	m_musicHandler.stopBackgroundMusic();

	m_musicHandler.setCurrMusic(track);
	newMusic.setLoop(true);
	newMusic.setVolume(80); //adjust
	if (!m_musicHandler.getMuteAllState())
	{
		newMusic.play();
	}
}

void Game::initPlayer()
{
	if (!m_player)
	{
		puts("not created");
		m_player = std::make_unique<Player>(m_world, m_startLocation);
		m_player->setSize(61, 61);
	}
	else
	{
		puts("im alive!");
		m_player->setPosition(m_startLocation);
		m_player->handleForwardState();
	}
}

void Game::initWorld()
{
	_view = sf::View(sf::FloatRect(300, 300, WINDOW_X/0.9, WINDOW_Y/0.9));
	m_world = std::make_unique<b2World>(m_gravity);
	m_map.setWorld(m_level, m_world);
	
	m_world->SetContactListener(&m_listner);
}

void Game::moveEnemy(sf::Time time)
{
	for (auto& enemy : m_movables)
	{
		enemy->move(time);
	}
}

void Game::moveBullets(sf::Time time)
{
	for (auto& bullet : m_bullets)
	{
		bullet->move(time);
	}
}

void Game::handleRestart()
{
	if (m_player->getNextLevelState())
	{
		m_player->setNextLevel(false);
		m_controller.switchState(GameStates::NEXT_LEVEL_S);
		setLevelsOrder();
		m_world.reset();
		initWorld();

		m_startLocation = m_map.getPlayerLocation();
		initPlayer();
		//call for reset of stats that we will be collecting in the future

		//reset everything and satrt a new level

	}

	if (m_restartRound)
	{
		m_restartRound = false;
		puts("new attempt");
	}
}

void Game::handleDeletionBullets()
{
	//m_bullets.erase(
	//	std::remove_if(m_bullets.begin(), m_bullets.end(),
	//		[](const std::unique_ptr<Movable>& movable) {
	//			if (Bullet* bullet = dynamic_cast<Bullet*>(movable.get())) {
	//				return bullet->isDestroyState();
	//			}
	//			return false;
	//		}),
	//	m_bullets.end());
}

void Game::fireBullet()
{
	static sf::Clock bulletCooldown;
	if (bulletCooldown.getElapsedTime().asSeconds() < 0.2f) 
	{
		return;
	}

	bulletCooldown.restart();
	auto bullet = FactoryMovables::createMovable(ObjectTypes::BULLET_T, m_world, { m_player->getPosition().x + 40, m_player->getPosition().y + 15 });
	m_bullets.push_back(std::move(bullet));
}