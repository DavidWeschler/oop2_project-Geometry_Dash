#include "Menu.h"
//#include "Game.h"
#include <iostream>

Menu::Menu(ChoosePlayer& choosePlayerState)
	: m_choosePlayer(choosePlayerState)
{
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));

	m_choosePlayer.setStates(this);

	setButtons();
}

void Menu::setButtons()
{	
	for (int i = 1; i <= 3; i++)
	{
		auto j = (i == 2) ? 1.5 : 1;
		m_buttons.push_back(Button(sf::Vector2f(i*WINDOW_X /4, (WINDOW_Y *2/5)),
			sf::Vector2f(j* WINDOW_X *1/10, j* WINDOW_X *1/10),
			m_resources.getButtonName(i-1), &rec[i - 1] /* & sf::RectangleShape()*/, &m_resources.getButtonTextures(i)));
	}
	for (int i = 1; i <=2; i++)
	{
		m_buttons.push_back(Button(sf::Vector2f((2*i + 1) * WINDOW_X / 8, (WINDOW_Y * 3 / 4)),
			sf::Vector2f(WINDOW_X * 3/64, WINDOW_X * 3/64),
			m_resources.getButtonName(i+2), &cir[i-1], &m_resources.getButtonTextures(i)));
	}

	//exit button
	m_buttons.push_back(Button(sf::Vector2f(WINDOW_X * 157/160, WINDOW_Y/30), sf::Vector2f(WINDOW_X / 64, WINDOW_X / 64) , m_resources.getButtonName(5), &cir[2], &m_resources.getButtonTextures(0)));// , &m_resources.getButtonTextures(i)));
}

GameState* Menu::handleChoice(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	for (int i = 0; i < NUM_OF_MENU_BUTTONS; i++)
	{
		if (m_buttons[i].getGlobalBound().contains(event.x, event.y))
		{
			if (m_buttons[i].getType() == SHAPE) {
				puts("SHAPE");
				return &m_choosePlayer;
			}
			else if (m_buttons[i].getType() == START) {
				puts("START");
			}
			else if (m_buttons[i].getType() == MUSIC) {
				puts("MUSIC");
			}
			else if (m_buttons[i].getType() == HIGH_SCORE) {
				puts("HIGH_SCORE");
			}
			else if (m_buttons[i].getType() == HOW_TO_PLAY) {
				puts("HOW_TO_PLAY");
			}
			else if (m_buttons[i].getType() == EXIT) {
				puts("EXIT");
				window.close();
			}
		}
	}
	return nullptr;
	
}

GameState* Menu::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		return handleChoice(event.mouseButton, window);
	}

	//Enlarge - will need to move to a funtion!
	for (int i = 0; i < NUM_OF_MENU_BUTTONS; i++)
	{
		(m_buttons[i].getGlobalBound().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) ?
			m_buttons[i].setScale(1.1f, 1.1f) : m_buttons[i].setScale(1.0f, 1.0f);
	}

	return nullptr;
}
   
void Menu::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color(0, 204, 204));
	//m_window.draw(m_background);
	for (int i = 0; i < NUM_OF_MENU_BUTTONS; i++)
	{
		m_buttons[i].draw(window);
	}
}   