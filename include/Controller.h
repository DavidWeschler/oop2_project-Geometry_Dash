#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameState.h"
#include "MusicManager.h"
#include "GlobalConsts.h"
#include "Singleton.h"
#include "ChoosePlayer.h"
#include "Menu.h"
#include "Game.h"
#include "NextLevelWindow.h"

class Controller
{
public:
	Controller();

	void run();
	void switchState(GameState* nextState);	//private?
	void switchState(GameStates nextState);
	bool playMusic() const;
	void muteMusic();
	void resumeMusic();
private:




	void switchTrack(int track);
	bool pauseMusic() const;
	void switchColors(int&);
	float m_transitionSpeed;
	sf::RenderWindow m_window;

	Singleton& m_resources = Singleton::instance();
	MusicManager& m_musicHandler = MusicManager::instance();

	GameState* m_currentState;

	//the states of game state
	Menu m_menuState;
	ChoosePlayer m_choosePlayerState;
	Game m_game;
	NextLevelWindow m_nextLevelWindow;
	//PausedState pausedState_;
	//PlayingState playingState_;

	sf::Clock m_clock;
	sf::Time m_time;

	sf::Sprite m_cursorSprite;

	sf::Music& m_backgroundMusic;

	float m_r;
	float m_g;
	float m_b;

	bool m_isMouseDragging = false;
	sf::Vector2f m_lastDown;
};