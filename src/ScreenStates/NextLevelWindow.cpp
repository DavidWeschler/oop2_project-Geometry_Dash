#include "ScreenStates/NextLevelWindow.h"
#include "ScreenStates/Game.h"

NextLevelWindow::NextLevelWindow(Controller& controller, Game& game)
	: m_controller(controller), m_game(game)
{
	setDisplayMembers();
	setButtons(controller);
}

void NextLevelWindow::handleEvent(const sf::Event& event, sf::RenderWindow& window, sf::Time time)
{
	for (auto& button : m_buttons)
	{
		button.execute(event);
	}
	
	for (int i = 0; i < 2; i++)
	{
		if (m_buttons[i].getGlobalBound().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		{
			m_buttons[i].setScale(1.1f, 1.1f);
		}
		else {
			m_buttons[i].setScale(1.0f, 1.0f);
		}
	}
}

void NextLevelWindow::draw(sf::RenderWindow& window, int r, int g, int b)
{

	auto S = [](auto subject, auto value) { return subject + std::to_string(value) + "\n"; };

	auto temp = 17;

	std::string gameStats = S("Number Of Attempts: ", temp) +
							S("\t\tTime: ", temp) +
							S("Number Of Jumps: ", temp);
		
	m_stats.setString(gameStats);
	m_background.setFillColor(sf::Color(r, g, b));
	window.draw(m_background);
	window.draw(m_wellDone);
	window.draw(m_stats);
	for (auto& button : m_buttons)
	{
		button.draw(window);
	}		
}

void NextLevelWindow::setButtons(Controller& controller)
{
	m_buttons.push_back(Button(sf::Vector2f(WINDOW_X*4/10, WINDOW_Y*2.5/3), sf::Vector2f(150, 150), BACK_TO_MENU, &m_resources.getMenuButtonTexture(5),
		std::move(std::make_unique<NextStateCommand>(controller, GameStates::MENU_S))));

	m_buttons.push_back(Button(sf::Vector2f(WINDOW_X *6/10, WINDOW_Y * 2.5 / 3), sf::Vector2f(150, 150), NEW_GAME, &m_resources.getMenuButtonTexture(6),
		std::move(std::make_unique<NextStateCommand>(controller, GameStates::GAME_S))));
}

void NextLevelWindow::setDisplayMembers()
{
	//set statistics text
	m_stats.setFont(m_resources.getFont());
	m_stats.setCharacterSize(50);
	m_stats.setFillColor(sf::Color(240, 196, 51));
	m_stats.setPosition(sf::Vector2f(WINDOW_X / 3.6, WINDOW_Y / 2.2));
	m_stats.setLineSpacing(1.5f);
	m_stats.setOutlineColor(sf::Color::Black);
	m_stats.setOutlineThickness(2);
	m_stats.setLetterSpacing(1.2f);

	//set backgrounds
	m_wellDone.setTexture(&m_resources.getWellDoneTexture());
	m_wellDone.setSize(sf::Vector2f(WINDOW_X * 109 / 200, WINDOW_Y * 19 / 90));
	m_wellDone.setPosition(sf::Vector2f(WINDOW_X / 4.5, WINDOW_Y / 7));
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));
}