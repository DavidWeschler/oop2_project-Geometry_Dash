#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ScreenStates/GameState.h"
#include "Singletones/MusicManager.h"
#include "Singletones/GlobalConsts.h"
#include "Singletones/TexturesManger.h"
#include "ScreenStates/ChoosePlayer.h"
#include "ScreenStates/Menu.h"
#include "ScreenStates/Game.h"
#include "ScreenStates/NextLevelWindow.h"

class Controller
{
public:
	Controller();

	void run();
	//void switchState(GameState* nextState);	//private?
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