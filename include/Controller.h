#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	bool playMusic() const;
	bool pauseMusic() const;
	void switchColors(int&);
	float m_transitionSpeed;
	sf::RenderWindow m_window;

	MusicManager& m_musicHandler = MusicManager::instance();

	GameState* m_currentState;

	//the states of game state
	Menu m_menuState;
	ChoosePlayer m_choosePlayerState;
	Game m_game;
	//PausedState pausedState_;
	//PlayingState playingState_;

	sf::Clock m_clock;
	sf::Time m_time;

	sf::Music& m_backgroundMusic;

	float m_r;
	float m_g;
	float m_b;
};