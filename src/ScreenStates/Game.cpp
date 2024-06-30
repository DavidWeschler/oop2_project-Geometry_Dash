#pragma region headers
#include <iostream>
#include <algorithm>
#include <ctime>	

#include "ScreenStates/Game.h"
#include "Singletones/GameEnityFactory.h"
#include "ButtonCommand/NextStateCommand.h"
#include "ScreenStates/Controller.h"
#include "ScreenStates/Menu.h"
#pragma endregion headers

Game::Game(Controller& controller)
	:m_map(m_movables, m_fixed), m_gravity(GRAVITY_X, GRAVITY_Y), m_controller(controller), m_shootSound(m_musicHandler.getShootSound())
{
	setLevelsOrder();
	initWorld();
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));
	m_startLocation = m_map.getPlayerLocation();
	m_bulletCooldown.restart();
	initPlayer();
	setButton(controller);
	setPrompt();
}

void Game::setButton(Controller& controller)
{
	m_exitButton = std::make_unique<Button>(
		sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30),
		sf::Vector2f(WINDOW_X / 32.f, WINDOW_X / 32.f),
		&m_resources.getBackButtonTexture(1),
		std::move(std::make_unique<NextStateCommand>(controller, GameStates::MENU_S)));
}

void Game::setPrompt()
{
	srand(std::time(NULL));
	auto prompt = rand() % NUM_OF_PROMPTS;
	m_promptTime = m_promptDisplay.restart();
	m_prompt.setSize({ WINDOW_X / 20 * 16, WINDOW_Y / 20 * 1 });
	m_prompt.setTexture(&m_resources.getPrompt(prompt));
}

void Game::setLevelsOrder()
{
	static int counter = 0;
	std::vector<int> levels = { 1, 2, 3, 4};
	std::default_random_engine randomize(static_cast<unsigned int>(std::time(nullptr)));
	if (counter == 0)
	{
		std::shuffle(levels.begin(), levels.end(), randomize);
		for (int num : levels) m_levelIndex.push(num);
	}
	m_level = m_levelIndex.front();
	m_levelIndex.pop();
	counter++;
	if (counter == NUM_OF_LEVELS) counter = 0;
	
	m_level = 1;							//remove! for debugigng only!!!///////////////////////////////////////////////////////////////
	//m_level = 3;							//remove! for debugigng only!!!///////////////////////////////////////////////////////////////
}

void Game::handleEvent(const sf::Event& event, sf::RenderWindow&)
{
	m_exitButton->execute(event);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_player->setJumping(true);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) fireBullet();
}

void Game::update(sf::Time time)
{
	handleWin();
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
		switchMusic();
		setReplaceMusic(false);
	}
}

void Game::draw(sf::RenderWindow& window, int r, int g, int b)
{
	static int offSet = 0;
	static int axisY = m_player->getPosition().y - 220;
	sf::View originalView = window.getView();

	window.clear();
	m_background.setFillColor(sf::Color(r, g, b));
	window.draw(m_background);

	adjustViewOffset(offSet);

	setCenterView((m_player->getPosition().x + 300) * 1.f, m_player->getPosition().y + offSet * 1.f);
	window.setView(getView());

	drawWorldObj(window);

	window.setView(window.getDefaultView());

	//draw constant elements
	m_exitButton->draw(window);
	drawPrompts(window);

	// Restore the original view
	window.setView(originalView);
}

void Game::setChosenPlayer(int i)
{
	m_player->setChosenPlayer(i);
}

void Game::setInterrupted(bool state)
{
	m_interrupted = state;
}

int Game::getGameStat(GameStats stat) const
{
	return m_stats[stat];
}

int Game::getPlayerStat(PlayerStats stat) const
{
	return m_player->getStat(stat);
}

void Game::switchMusic()
{
	srand(std::time(NULL));
	int track = 1 + rand() % (NUM_OF_TRACKS-1);

	sf::Music& newMusic = m_musicHandler.getMusicTrack(track);

	m_musicHandler.stopBackgroundMusic();

	m_musicHandler.setCurrMusic(track);
	newMusic.setLoop(true);
	newMusic.setVolume(80);
	if (!m_musicHandler.getMuteAllState()) newMusic.play();
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
		throw std::runtime_error("no player loaded from the level");
	}

	m_stats = std::vector<int>(2, 0);
}

void Game::initWorld()
{
	setView(sf::FloatRect(300, 300, WINDOW_X / 0.9, WINDOW_Y / 0.9));
	m_world = std::make_unique<b2World>(m_gravity);
	m_map.setWorld(m_level, m_world);
	
	m_world->SetContactListener(&m_listener);
}

void Game::moveEnemy(sf::Time time)
{
	for (auto& enemy : m_movables) enemy->move(time);
}

void Game::moveBullets(sf::Time time)
{
	for (auto& bullet : m_bullets) bullet->move(time);
}

void Game::handleRestart()
{
	//reset level
	if (m_player->isSpiked())
	{
		m_promptTime = m_promptDisplay.restart();
		auto prompt = rand() % NUM_OF_PROMPTS;
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
	auto rmv = [](const std::unique_ptr<Movable>& object) {
		return object->isDestroyState();
		};

	auto removedEnd = std::remove_if(m_bullets.begin(), m_bullets.end(), rmv);
	m_bullets.erase(removedEnd, m_bullets.end());

	auto removedRobots = std::remove_if(m_movables.begin(), m_movables.end(), rmv);
	auto numRemoved = std::distance(removedRobots, m_movables.end());
	m_stats[ROBOTS_KILLED_STAT] += static_cast<int>(numRemoved);
	m_movables.erase(removedRobots, m_movables.end());

}

void Game::fireBullet()
{
	if (m_bulletCooldown.getElapsedTime().asSeconds() < 0.2f) return;

	m_bulletCooldown.restart();	
	m_bullets.push_back(GameEnityFactory<Movable>::create(BULLET_C, m_world, sf::Vector2f(m_player->getPosition().x + 40, m_player->getPosition().y + 15)));
	m_stats[BULLETS_SHOT_STAT]++;

	if (!m_musicHandler.getMuteAllState()) m_shootSound.play();
}

void Game::handleWin()
{
	if (m_player->getNextLevelState() && !m_player->isSpiked() || m_interrupted)
	{
		m_bullets.clear();
		m_controller.saveStats();
		m_player->setNextLevel(false);
		auto selection = m_player->getSetNum();

		if (!m_interrupted) m_controller.switchState(GameStates::NEXT_LEVEL_S);

		m_interrupted = false;
		m_world.reset();
		setLevelsOrder();
		initWorld();
		m_player.reset();

		m_startLocation = m_map.getPlayerLocation();
		initPlayer();
		m_player->setChosenPlayer(selection);
	}
}

//drawing
void Game::adjustViewOffset(int& offSet)
{
	if (m_player->getStateType() == PlayerState::UPSIDEDOWN_S)
	{
		if (offSet < 200)
			offSet++;
	}
	else
	{
		if (offSet > -200)
			offSet--;
	}
}

void Game::drawWorldObj(sf::RenderWindow& window)
{
	for (auto obj = m_movables.begin(); obj != m_movables.end(); obj++) (*obj)->draw(window);
	
	for (auto& bullet : m_bullets) bullet->draw(window);
	
	auto playerX = m_player->getPosition().x;
	auto playerY = m_player->getPosition().y;
	for (auto obj = m_fixed.begin(); obj != m_fixed.end(); obj++)
	{
		auto fixedX = (*obj)->getPosition().x;
		auto fixedY = (*obj)->getPosition().y;

		if (std::abs(fixedX - playerX) < 1250 && std::abs(fixedY - playerY) < 750.0f) 
			(*obj)->draw(window);
	}
	m_player->draw(window);
}

void Game::drawPrompts(sf::RenderWindow& window)
{
	if (m_promptTime.asSeconds() < sf::seconds(3.5f).asSeconds() && !m_player->isSpiked() && m_player->getStat(NUM_OF_ATTEMPTS_STAT)>0)
	{
		m_prompt.setPosition(WINDOW_X*0.12f, WINDOW_Y*7/18);
		window.draw(m_prompt);
	}
}