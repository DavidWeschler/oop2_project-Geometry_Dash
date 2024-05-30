#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Button.h"
#include "Singleton.h"
#include "ChoosePlayer.h"
#include "GameState.h"

class Menu : public GameState
{
public:
	Menu(ChoosePlayer& choosePlayerState); //will get more: play, help, endgame screens, pause menu

private:
	void setButtons();
	virtual GameState* handleEvent(const sf::Event&, sf::RenderWindow&);
	virtual void draw(sf::RenderWindow&);


	virtual void update(/*sf::Time*/) {};

	GameState* handleChoice(const sf::Event::MouseButtonEvent&, sf::RenderWindow&);
	Singleton& m_resources = Singleton::instance();

	sf::RectangleShape m_background;
	sf::RenderWindow* m_window;

	std::vector<Button> m_buttons;

	sf::Vector2i m_winSize;

	ChoosePlayer& m_choosePlayer;


	sf::RectangleShape rec[3];
	sf::CircleShape cir[3];

};