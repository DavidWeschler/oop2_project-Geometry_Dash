#include "ScreenStates/Statistics.h"
#include <Windows.h>

Statistics::Statistics(Controller& controller)
	: m_controller(controller)
{
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));

	m_statsBackground.setSize(sf::Vector2f(WINDOW_X / 1.2, WINDOW_Y / 1.2));
	m_statsBackground.setTexture(&m_resources.getStatsTexture());
	m_statsBackground.setOrigin(sf::Vector2f(m_statsBackground.getSize().x / 2, m_statsBackground.getSize().y / 2));
	m_statsBackground.setPosition({ WINDOW_X / 2, WINDOW_Y / 2 });


	//set statistics text
	m_stats.setFont(m_resources.getFont());
	m_stats.setCharacterSize(40);
	m_stats.setFillColor(sf::Color(240, 196, 51));
	m_stats.setPosition(sf::Vector2f(WINDOW_X / 3.6, WINDOW_Y / 5.2));
	m_stats.setLineSpacing(1.23f);
	m_stats.setOutlineColor(sf::Color::Black);
	m_stats.setOutlineThickness(2);
	m_stats.setLetterSpacing(1.2f);

	setButtons(controller);
}

void Statistics::handleEvent(const sf::Event& event, sf::RenderWindow& window, sf::Time time)
{
	//these function happens in every screenstate! move up in the tree!
	for (auto& button : m_buttons)
	{
		button.execute(event);
	}
	for (int i = 0; i < m_buttons.size(); i++)
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

void Statistics::draw(sf::RenderWindow& window, int r, int g, int b)
{
	m_background.setFillColor(sf::Color(r, g, b));
	window.draw(m_background);
	window.draw(m_statsBackground);
	auto S = [](auto subject, auto value) { return subject + std::to_string(value) + "\n"; };

	int temp = 17;

	std::string gameStats = S("Number Of Attempts: ", temp) +
		S("\t\tTime: ", temp) +
		S("Number Of Jumps: ", temp) +
		S("More Stuff: ", temp) +
		S("More Stuff 2: ", temp) +
		S("More Stuff 3: ", temp) +
		S("More Stuff 4: ", temp) +
		S("More Stuff 5: ", temp) +
		S("More Stuff 6: ", temp) +
		S("More Stuff 7: ", temp);


	m_stats.setString(gameStats);
	window.draw(m_stats);

	for (auto& button : m_buttons)
	{
		button.draw(window);
	}
}

void Statistics::setButtons(Controller& controller)
{
	//return button
	m_buttons.push_back(Button(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 32, WINDOW_X / 32), BACK_TO_MENU, &m_resources.getBackButtonTexture(1), std::move(std::make_unique<NextStateCommand>(controller, GameStates::MENU_S))));
}