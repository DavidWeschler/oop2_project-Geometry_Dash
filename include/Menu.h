#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Button.h"
#include "Singleton.h"
#include "ChoosePlayer.h"
#include "GameState.h"
#include "Game.h"

class ChoosePlayer;
class Game;

class Menu : public GameState
{
public:
	Menu(ChoosePlayer& choosePlayerState, Game& game); //will get more: play, help, endgame screens, pause menu
	void setChosenPlayer(int i);

private:
	void setButtons();
	virtual GameState* handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
	virtual void draw(sf::RenderWindow&);
	void markButton(sf::RenderWindow& window);


	virtual void update(sf::Time) {};

	GameState* handleChoice(const sf::Event::MouseButtonEvent&, sf::RenderWindow&);
	Singleton& m_resources = Singleton::instance();

	sf::RenderWindow* m_window;
	sf::RectangleShape m_background;

	std::vector<Button> m_buttons;

	ChoosePlayer& m_choosePlayer;
	Game& m_game;


	sf::RectangleShape rec[3];
	sf::CircleShape cir[3];

};