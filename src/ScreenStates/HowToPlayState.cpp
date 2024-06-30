#pragma region headers
#include "ScreenStates/HowToPlayState.h"
#include "ScreenStates/Controller.h"
#include "ButtonCommand/HowToPlayCommand.h"
#pragma endregion headers

HowToPlayState::HowToPlayState(Controller& controller)
	: m_controller(controller)
{
	m_explanationIndex = 0;
	setBackgrounds();
	setButtons(controller);
}

void HowToPlayState::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	for (auto& button : m_buttons) button.execute(event);
	
	m_explanationIndex = std::max(m_explanationIndex, 0);

	if (m_explanationIndex >= NUM_OF_HOW_TO_PLAY)
	{
		m_controller.switchState(GameStates::MENU_S);
		m_explanationIndex = 0;
	}

	for (int i = 0; i < m_buttons.size(); i++)
	{
		if (m_buttons[i].getGlobalBound().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			m_buttons[i].setScale(1.1f, 1.1f);
		else 
			m_buttons[i].setScale(1.0f, 1.0f);	
	}
}

void HowToPlayState::setButtons(Controller& controller)
{
	m_buttons.push_back(Button(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 32, WINDOW_X / 32), &m_resources.getBackButtonTexture(1),std::move(std::make_unique<NextStateCommand>(controller, GameStates::MENU_S))));
	m_buttons.push_back(Button(sf::Vector2f(WINDOW_X *3/44, WINDOW_Y / 2), sf::Vector2f(WINDOW_X / 10, WINDOW_X / 10), &m_resources.getMenuButtonTexture(8),std::move(std::make_unique<HowToPlayCommand>(m_explanationIndex, -1)))); //left
	m_buttons.push_back(Button(sf::Vector2f(WINDOW_X * 41/44 , WINDOW_Y / 2), sf::Vector2f(WINDOW_X / 10, WINDOW_X / 10), &m_resources.getMenuButtonTexture(7),std::move(std::make_unique<HowToPlayCommand>(m_explanationIndex, 1)))); //right
}

void HowToPlayState::setBackgrounds()
{
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground(0));
	m_innerBackground.setTexture(&m_resources.getHowToPlayTexture(-1));
	m_innerBackground.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_currSlide.setSize({ 1000 * 1.2, 360 * 1.2 });
	m_currSlide.setOrigin(m_currSlide.getSize().x / 2, m_currSlide.getSize().y / 2);
	m_currSlide.setPosition(WINDOW_X / 2, WINDOW_Y / 2);
}

void HowToPlayState::draw(sf::RenderWindow& window, int r, int g, int b)
{
	m_background.setFillColor(sf::Color(r, g, b));
	m_currSlide.setTexture(&m_resources.getHowToPlayTexture(m_explanationIndex));
	window.draw(m_background);
	window.draw(m_innerBackground);
	window.draw(m_currSlide);

	for (auto& button : m_buttons) button.draw(window);	
}