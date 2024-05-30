#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Menu.h"
#include "ChoosePlayer.h"


class Controller
{
public:
	Controller();

	void run();
private:
	sf::RenderWindow m_window;

	GameState* m_currentState;

	Menu m_menuState;
	ChoosePlayer m_choosePlayerState;
	//PausedState pausedState_;
	//PlayingState playingState_;

};