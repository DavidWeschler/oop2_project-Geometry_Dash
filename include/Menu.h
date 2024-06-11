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
	virtual GameState* handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
	virtual void draw(sf::RenderWindow& window, int r, int g, int b);
	virtual void update(sf::Time) {};
	void setButtons();
	void markButton(sf::RenderWindow& window);
	GameState* handleChoice(const sf::Event::MouseButtonEvent&, sf::RenderWindow&);

	Singleton& m_resources = Singleton::instance();

	sf::RenderWindow* m_window;
	sf::RectangleShape m_background;
	sf::RectangleShape m_backgroundText;
	std::vector<Button> m_buttons;
	ChoosePlayer& m_choosePlayer;
	Game& m_game;
	sf::RectangleShape rec[3];
	sf::CircleShape cir[3];
};