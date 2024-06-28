#include "ScreenStates/Game.h"
#include <iostream>
#include <ranges>	//cgeck this
#include "ButtonCommand/NextStateCommand.h"
#include "ScreenStates/Controller.h"
#include "ScreenStates/Menu.h"
#include <ctime>
#include <algorithm> // Include for std::for_each
#include "Singletones/GameEnityFactory.h"

Game::Game(Controller& controller, sf::Music& music)
	:m_map(m_movables, m_fixed), m_gravity(GRAVITY_X, GRAVITY_Y), m_controller(controller),
	 m_backgroundMusic(music)
{
	srand(std::time(NULL));
	auto prompt = rand() % NUM_OF_PROMPTS;
	m_promptTime = m_promptDisplay.restart();

	setLevelsOrder();
	initWorld();

	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));

	//m_prompt.setSize({ m_resources.getPrompt(prompt).getSize().x * 0.7f , m_resources.getPrompt(prompt).getSize().y * 0.7f }); //adjust
	m_prompt.setSize({ WINDOW_X / 6, WINDOW_Y / 6 });
	m_prompt.setTexture(&m_resources.getPrompt(prompt));

	m_pauseButton= std::make_unique<Button>(
		sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), 
		sf::Vector2f(WINDOW_X / 32.f, WINDOW_X / 32.f), 
		RETURN, 
		&m_resources.getBackButtonTexture(2),
		std::move(std::make_unique<NextStateCommand>(controller, GameStates::MENU_S)));

	m_startLocation = m_map.getPlayerLocation();
	initPlayer();
}

void Game::setLevelsOrder()
{
	static int counter = 0;
	std::vector<int> levels = { 1, 2, 3, 4}; //as the size of NUM_OF_LEVELS const!
	std::default_random_engine randomize(static_cast<unsigned int>(std::time(nullptr))); //casting to unsigned int
	if (counter == 0)
	{
		std::shuffle(levels.begin(), levels.end(), randomize);
		for (int num : levels) {
			m_levelIndex.push(num);
		}
	}
	//m_level = m_levelIndex.front();
	m_level = 1;
	m_levelIndex.pop();
	counter++;
	if (counter == 2)
	{
		counter = 0;
	}
	m_level = 1; //remove! for debugigng only!!!
}



Game::~Game()
{
	//// Destroy all bodies in the Box2D world
	//b2Body* body = m_world->GetBodyList();
	//while (body)
	//{
	//	b2Body* next = body->GetNext();
	//	m_world->DestroyBody(body);
	//	body = next;
	//}

	//// Optionally clear other Box2D elements like joints and contacts
	//m_world->ClearForces();
	////m_world->ClearJoints(); // Uncomment if necessary
	////m_world->ClearContacts(); // Uncomment if necessary
}

void Game::handleEvent(const sf::Event& event, sf::RenderWindow&, sf::Time)		//Time needs to go! not used in any handle event function
{
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

	m_prompt.setPosition(m_player->getStartLocation().x - 140, m_player->getStartLocation().x - 300); //adjust
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
	//_view.setCenter(m_player->getPosition().x + 300, m_player->getPosition().y + counter);
	_view.setCenter((m_player->getPosition().x + 300) *1.f, m_player->getPosition().y + counter* 1.f);

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

	if (m_promptTime.asSeconds() < sf::seconds(3.0f).asSeconds())
	{
		m_prompt.setPosition(m_player->getStartLocation().x - 140, m_player->getStartLocation().x - 300); //adjust
		m_prompt.setSize({ WINDOW_X / 6, WINDOW_Y / 6 });
		window.draw(m_prompt);
	}


	// Restore the original view
	window.setView(originalView);
}

void Game::update(sf::Time time)
{
	handleRestart();
	handleDeletionBullets();
	m_promptTime = m_promptDisplay.getElapsedTime();

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
		m_player = std::make_unique<Player>(m_world, m_startLocation);
		m_player->setSize(61, 61);
	}
	else
	{
		//throw...
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

		auto selection = m_player->getChosenPlayer();
		m_world.reset();
		setLevelsOrder();
		initWorld();
		m_player.reset();

		m_startLocation = m_map.getPlayerLocation();
		initPlayer();
		m_player->setChosenPlayer(selection);
		//call for reset of stats that we will be collecting in the future

		//reset everything and satrt a new level

	}

	if (m_player->isSpiked())
	{
		m_promptTime = m_promptDisplay.restart();
		auto prompt = rand() % NUM_OF_PROMPTS;
		m_prompt.setSize({ WINDOW_X/ m_resources.getPrompt(prompt).getSize().x * 0.7f, WINDOW_Y / m_resources.getPrompt(prompt).getSize().y * 0.7f });
		m_prompt.setTexture(&m_resources.getPrompt(prompt));

		m_player->setOnGround(true);
		m_player->setGroundJumpDelta(0);
		m_player->setJumping(false);
		m_player->arrowTouch(false);

		for (auto& robot : m_movables)
		{
			b2Vec2 startRobot = b2Vec2(robot->getStartPosition().x / 30.f, robot->getStartPosition().y / 30.f);
			robot->setTransform(startRobot);
			robot->setPosition(robot->getStartPosition());
		}
	}
}

void Game::handleDeletionBullets()
{

	auto rmv = [](const std::unique_ptr<Movable>& bullet)
		{
			return bullet->isDestroyState();
		};

	std::remove_if(m_bullets.begin(), m_bullets.end(), rmv);

	//bool ok = false;
	//for (int i = 0; i < m_bullets.size(); i++)
	//{
	//	if (m_bullets[i]->isDestroyState())
	//	{
	//		ok = true;
	//		break;
	//		//m_bullets.erase(m_bullets.begin() + i);
	//	}
	//}
	//if (ok)
	//{
	//	m_bullets.pop_back();
	//}
}

void Game::fireBullet()
{
	static sf::Clock bulletCooldown;
	if (bulletCooldown.getElapsedTime().asSeconds() < 0.2f) 
	{
		return;
	}

	bulletCooldown.restart();

	m_bullets.push_back(GameEnityFactory<Movable>::create(BULLET_C, m_world, sf::Vector2f(m_player->getPosition().x + 40, m_player->getPosition().y + 15)));


	//auto bullet = FactoryMovables::createMovable(ObjectTypes::BULLET_T, m_world, { m_player->getPosition().x + 40, m_player->getPosition().y + 15 });
	//m_bullets.push_back(std::move(bullet));
}