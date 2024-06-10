#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Menu.h"
#include "ChoosePlayer.h"
#include "Game.h"


class Controller
{
public:
	Controller();

	void run();
private:
	void switchColors(int&, float&, float&, float&);
	//void handleMusic();

	float m_transitionSpeed;
	sf::RenderWindow m_window;

	GameState* m_currentState;

	//the states of game state
	Menu m_menuState;
	ChoosePlayer m_choosePlayerState;
	Game m_game;
	//PausedState pausedState_;
	//PlayingState playingState_;

	sf::Clock m_clock;
	sf::Time m_time;
};