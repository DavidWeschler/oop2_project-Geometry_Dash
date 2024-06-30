#pragma once

#pragma region headers

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Singletones/TexturesManger.h"
#include "ScreenStates/GameState.h"
#include "ScreenStates/ChoosePlayer.h"
#include "ScreenStates/Menu.h"
#include "ScreenStates/Game.h"
#include "ScreenStates/NextLevelWindow.h"
#include "ScreenStates/HowToPlayState.h"
#include "ScreenStates/Statistics.h"

#pragma endregion headers

class Controller
{
public:
	Controller();

	void run();
	void switchState(GameStates nextState);
	void saveStats();
private:
	void updateCursor(const sf::Event& event);
	void enableWindowDragging(const sf::Event& event);
	void switchColors(int& phase);

	TexturesManger& m_resources = TexturesManger::instance();
	
	sf::RenderWindow m_window;
	sf::Sprite m_cursorSprite;
	sf::Clock m_clock;
	sf::Time m_time;

	GameState* m_currentState;	
	Menu m_menuState;
	ChoosePlayer m_choosePlayerState;
	Game m_game;
	NextLevelWindow m_nextLevelWindow;
	HowToPlayState m_howToPlay;
	Statistics m_stats;

	sf::Vector2f m_lastDown;
	bool m_isMouseDragging = false;
	float m_transitionSpeed;
	float m_r;
	float m_g;
	float m_b;
};