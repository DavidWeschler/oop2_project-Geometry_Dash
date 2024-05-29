#pragma once

#include <SFML/Graphics.hpp>
//#include <fstream>
#include <vector>
#include <string>
//#include "Button.h"
#include "Singleton.h"

class Menu
{
public:
	Menu();
	void run();

private:
	void setButtons();
	void handleChoice(const sf::Event::MouseButtonEvent&);
	//void openFile();
	void draw();

	//Singleton& m_resources = Singleton::instance();

	sf::RectangleShape m_background;
	sf::RenderWindow m_window;

	//std::vector<Button> m_buttons;

	sf::Vector2i m_winSize;
};