#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Button.h"
#include "Singleton.h"

#include "GameState.h"

#include "MusicManager.h"

#include "ButtonCommand.h"
#include "ChoosePlayerCommand.h"
#include "MusicCommand.h"
#include "NextStateCommand.h"
#include "ExitCommand.h"
#include "LinkedInCommand.h"

class ChoosePlayer;
class Game;
class Controller;

class Menu : public GameState
{
public:
	Menu(ChoosePlayer& choosePlayerState, Game& game, Controller& controller, sf::Music& backgroundMusic, sf::RenderWindow& window); //will get more: play, help, endgame screens, pause menu
	void setChosenPlayer(int i);

private:
	virtual void handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
	virtual void draw(sf::RenderWindow& window, int r, int g, int b);
	virtual void update(sf::Time) {};
	void setButtons(Controller& controller, sf::Music& backgroundMusic, sf::RenderWindow& window);
	void markButton(sf::RenderWindow& window);
	//void handleChoice(const sf::Event::MouseButtonEvent&, sf::RenderWindow&);

	Singleton& m_resources = Singleton::instance();
	MusicManager& m_musicHandler = MusicManager::instance();

	//sf::RenderWindow& m_window;
	sf::RectangleShape m_background;
	sf::RectangleShape m_backgroundText;
	std::vector<Button> m_buttons;
	std::vector<std::unique_ptr<ButtonCommand>> m_buttonCommands;
	ChoosePlayer& m_choosePlayer;
	Game& m_game;
};