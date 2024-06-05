#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory> // Required for std::unique_ptr
#include <Box2D/Box2D.h>
#include <Player.h>
#include "Button.h"
#include "Singleton.h"
#include "GameState.h"
#include "Menu.h"
#include "WorldMap.h"
//include "PauseMenu.h"

class Menu;

class Game : public GameState
{
public:
	Game(int levelNum);
	Singleton& m_resources = Singleton::instance();

	virtual GameState* handleEvent(const sf::Event&, sf::RenderWindow&);
	virtual void draw(sf::RenderWindow&);
	virtual void update(/*sf::Time*/) {};

	void setChosenPlayer(int i);


	void setState(Menu*);

private:
	Player m_player;
	sf::Vector2f m_startLocation;
	int m_level;
	//std::unique_ptr<Button> m_pauseButton;	//this didnt work ;(
	std::vector<Button> m_pauseButton;
	sf::RectangleShape m_background;
	Menu* m_menuState;
	WorldMap m_map;

	sf::CircleShape m_cir;


	//--------------BOX2D-------------
	b2Vec2 m_gravity;
	b2World m_world;
};