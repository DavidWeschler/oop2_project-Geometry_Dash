#include "Menu.h"
//#include "Game.h"
#include <iostream>

Menu::Menu()
	//: m_choosePlayer(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 1.2, sf::VideoMode::getDesktopMode().height / 1.2))
{
	m_winSize.x = sf::VideoMode::getDesktopMode().width / 1.2;
	m_winSize.y = sf::VideoMode::getDesktopMode().height / 1.2;
	//m_background.setTexture(&m_resources.getMenuBackground());
	m_background.setSize(sf::Vector2f(m_winSize));

	setButtons();
}

void Menu::run()
{
	m_window.create(sf::VideoMode(m_winSize.x, m_winSize.y), "Geometry Dash", sf::Style::None);

	while (m_window.isOpen())
	{
		m_window.clear(sf::Color(0, 204, 204));
		draw();
		m_window.display();

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				handleChoice(event.mouseButton);
				break;
			}
		}

		for (int i = 0; i < NUM_OF_MENU_BUTTONS; i++)
		{
			(m_buttons[i].getGlobalBound().contains(sf::Mouse::getPosition(m_window).x,	sf::Mouse::getPosition(m_window).y)) ? 
			 m_buttons[i].setScale(1.1f, 1.1f) : m_buttons[i].setScale(1.0f, 1.0f);
		}
	}
}

void Menu::setButtons()
{
	std::cout << m_winSize.x << "   " << m_winSize.y << "\n";
	
	for (int i = 1; i <= 3; i++)
	{
		auto j = (i == 2) ? 1.5 : 1;
		m_buttons.push_back(Button(sf::Vector2f(i*m_winSize.x /4, (m_winSize.y *2/5)),
			sf::Vector2f(j*m_winSize.x*1/10, j*m_winSize.x*1/10),
			m_resources.getButtonName(i-1), &rec[i-1]));// , &m_resources.getButtonTextures(i)));
	}
	for (int i = 1; i <=2; i++)
	{
		m_buttons.push_back(Button(sf::Vector2f((2*i + 1) * m_winSize.x / 8, (m_winSize.y * 3 / 4)),
			sf::Vector2f(m_winSize.x * 3/64, m_winSize.x * 3/64),
			m_resources.getButtonName(i+2), &cir[i-1]));// , &m_resources.getButtonTextures(i)));
	}

	//exit button
	m_buttons.push_back(Button(sf::Vector2f(m_winSize.x * 157/160, m_winSize.y/30), sf::Vector2f(m_winSize.x / 64, m_winSize.x / 64) , m_resources.getButtonName(5), &cir[2]));// , &m_resources.getButtonTextures(i)));
}

void Menu::handleChoice(const sf::Event::MouseButtonEvent& event)
{
	for (int i = 0; i < NUM_OF_MENU_BUTTONS; i++)
	{
		if (m_buttons[i].getGlobalBound().contains(event.x, event.y))
		{
			if (m_buttons[i].getType() == SHAPE) {				
				puts("SHAPE");
				//m_choosePlayer.go(m_window);
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
				m_window.close();
			}
		}
	}
}
  
   
void Menu::draw()
{
	//m_window.draw(m_background);
	for (int i = 0; i < NUM_OF_MENU_BUTTONS; i++)
	{
		m_buttons[i].draw(m_window);
	}
}   