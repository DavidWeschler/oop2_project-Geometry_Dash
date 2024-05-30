#pragma once	

#include "SFML/Graphics.hpp"
#include "Button.h"
#include "Singleton.h"

class ChoosePlayer
{
public:
	ChoosePlayer(sf::Vector2i windowSize);

	void go(sf::RenderWindow& window);
private:
	void setButtons();
	void handleChoice(const sf::Event::MouseButtonEvent& event, bool& ret);
	void draw(sf::RenderWindow& window);

	Singleton& m_resources = Singleton::instance();

	sf::RenderWindow* m_window;

	std::vector<Button> m_exitButton;
	std::vector<Button> m_setsButtons;

	sf::Vector2i m_winSize;


	sf::CircleShape m_cir;
	sf::RectangleShape m_rec[NUM_OF_CHOOSE_SETS];
};