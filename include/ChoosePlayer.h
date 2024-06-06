#pragma once	

#include "SFML/Graphics.hpp"
#include "Button.h"
#include "Singleton.h"
#include "GameState.h"
#include "Menu.h"

class Menu;

class ChoosePlayer : public GameState
{
public:
	ChoosePlayer();

	virtual GameState* handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
	virtual void update(sf::Time) {};
	virtual void draw(sf::RenderWindow& window);

	void setStates(Menu* menu);

	void markChoice(sf::RenderWindow& window);
private:
	void setButtons();
	void handleChoice(const sf::Event::MouseButtonEvent&, sf::RenderWindow&);

	Singleton& m_resources = Singleton::instance();

	Menu* m_menuState;

	sf::RenderWindow* m_window;
	sf::RectangleShape m_background;

	std::vector<Button> m_exitButton;
	std::vector<Button> m_setsButtons;

	sf::CircleShape m_cir;
	sf::RectangleShape m_rec[NUM_OF_CHOOSE_SETS];
};