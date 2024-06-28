#include "ScreenStates/Statistics.h"
#include "ScreenStates/Game.h"
#include <Windows.h>	//why?

Statistics::Statistics(Controller& controller, Game& game)
	: m_controller(controller), m_game(game),
	 m_button(sf::Vector2f(WINDOW_X * 157 / 160.f, WINDOW_Y / 30.f), sf::Vector2f(WINDOW_X / 32.f, WINDOW_X / 32.f), BACK_TO_MENU, &m_resources.getBackButtonTexture(1), std::move(std::make_unique<NextStateCommand>(controller, GameStates::MENU_S)))
{
	setBackgrounds();
}

void Statistics::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	m_button.execute(event);

	if (m_button.getGlobalBound().contains(sf::Mouse::getPosition(window).x * 1.f, sf::Mouse::getPosition(window).y * 1.f))
	{
		m_button.setScale(1.1f, 1.1f);
	}
	else {
		m_button.setScale(1.0f, 1.0f);
	}
}

void Statistics::draw(sf::RenderWindow& window, int r, int g, int b)
{
	m_background.setFillColor(sf::Color(r, g, b));
	window.draw(m_background);
	window.draw(m_statsBackground);
	auto S = [](auto subject, auto value) { return subject + std::to_string(value) + "\n"; };

	int temp = 17;

	std::string gameStats = 
		S("Number Of Attempts: \t\t\t\t\t\t", m_game.getGameStat(NUM_OF_ATTEMPTS_STAT)) +	// v
		S("Time:   \t\t\t\t\t\t\t\t\t\t\t", temp) +		//handle in game
		S("Number Of Jumps:  \t\t\t\t\t\t\t", m_game.getPlayerStat(NUM_OF_JUMPS_STAT)) +	// v
		S("Bullets Shot:  \t\t\t\t\t\t\t\t", m_game.getGameStat(BULLETS_SHOT_STAT)) +	// v
		S("Robots Killed:  \t\t\t\t\t\t\t\t", temp) +	//handle in game
		S("Shot Accuracy:\t\t\t\t\t\t\t\t", temp) +		//handle in stats (here)
		S("SpaceShip Portals:   \t\t\t\t\t\t", m_game.getPlayerStat(SPACESHIP_PORTAL_STAT)) +	// v
		S("Gravity Portals: \t\t\t\t\t\t\t", m_game.getPlayerStat(GRAVITY_PORTAL_STAT)) +	// v
		S("Killed By Robot:   \t\t\t\t\t\t\t", m_game.getPlayerStat(KILLED_BY_ROBOT_STAT)) +	// v
		S("Killed by Spikes:   \t\t\t\t\t\t\t", m_game.getPlayerStat(KILLET_BY_SPIKE_STAT));	// v


	m_stats.setString(gameStats);
	window.draw(m_stats);

	m_button.draw(window);
}

void Statistics::setBackgrounds()
{
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));
	m_statsBackground.setSize(sf::Vector2f(WINDOW_X / 1.2f, WINDOW_Y / 1.2f));
	m_statsBackground.setTexture(&m_resources.getStatsTexture());
	m_statsBackground.setOrigin(sf::Vector2f(m_statsBackground.getSize().x / 2.f, m_statsBackground.getSize().y / 2.f));
	m_statsBackground.setPosition({ WINDOW_X / 2.f, WINDOW_Y / 2.f });

	//set statistics text
	m_stats.setFont(m_resources.getFont());
	m_stats.setCharacterSize(40);
	m_stats.setFillColor(sf::Color(240, 196, 51));
	m_stats.setPosition(sf::Vector2f(WINDOW_X / 5.8f, WINDOW_Y / 5.2f));
	m_stats.setLineSpacing(1.23f);
	m_stats.setOutlineColor(sf::Color::Black);
	m_stats.setOutlineThickness(2.f);
	m_stats.setLetterSpacing(1.2f);
}