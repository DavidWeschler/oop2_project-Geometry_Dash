#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Menu.h"
#include "ChoosePlayer.h"
#include "Game.h"
#include "MusicManager.h"

const int RGB_UPPER_LIMIT = 240;
const int RGB_LOWER_LIMIT = 100;

class Controller
{
public:
	Controller();

	void run();
private:
	void switchColors(int&);

	MusicManager& m_resources = MusicManager::instance();

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

	float m_r;
	float m_g;
	float m_b;
};