#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Button.h"
#include "Singleton.h"
#include "ChoosePlayer.h"

class Menu
{
public:
	Menu();
	void run();

private:
	void setButtons();
	void handleChoice(const sf::Event::MouseButtonEvent&);
	void draw();

	Singleton& m_resources = Singleton::instance();

	sf::RectangleShape m_background;
	sf::RenderWindow m_window;

	std::vector<Button> m_buttons;

	sf::Vector2i m_winSize;

	ChoosePlayer m_choosePlayer;


	sf::RectangleShape rec[3];
	sf::CircleShape cir[3];
};