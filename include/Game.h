#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Button.h"
#include "Singleton.h"
#include "GameState.h"
#include "Menu.h"
//include "PauseMenu.h"

class Menu;

class Game : public GameState
{
public:
	Game();
	Singleton& m_resources = Singleton::instance();

	virtual GameState* handleEvent(const sf::Event&, sf::RenderWindow&);
	virtual void draw(sf::RenderWindow&);
	virtual void update(/*sf::Time*/) {};


	void setState(Menu*);

private:

	//Button m_pauseButton;
	sf::RectangleShape m_background;
	Menu* m_menuState;

	sf::CircleShape m_cir;
};