#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ScreenStates/GameState.h"
#include "Singletones/GlobalConsts.h"
#include "Singletones/TexturesManger.h"
#include "ScreenStates/ChoosePlayer.h"
#include "ScreenStates/Menu.h"
#include "ScreenStates/Game.h"
#include "ScreenStates/NextLevelWindow.h"
#include "ScreenStates/HowToPlayState.h"
#include "ScreenStates/Statistics.h"

class Controller
{
public:
	Controller();

	void run();
	//void switchState(GameState* nextState);	//private?
	void switchState(GameStates nextState);
private:
	void switchColors(int& phase);

	float m_transitionSpeed;
	sf::RenderWindow m_window;

	TexturesManger& m_resources = TexturesManger::instance();

	GameState* m_currentState;

	//the states of game state
	Menu m_menuState;
	ChoosePlayer m_choosePlayerState;
	Game m_game;
	NextLevelWindow m_nextLevelWindow;
	HowToPlayState m_howToPlay;
	Statistics m_stats;

	sf::Clock m_clock;
	sf::Time m_time;

	sf::Sprite m_cursorSprite;

	float m_r;
	float m_g;
	float m_b;

	bool m_isMouseDragging = false;
	sf::Vector2f m_lastDown;
};