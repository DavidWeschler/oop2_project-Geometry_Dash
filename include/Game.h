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
#include "Static.h"

#include "CollisionHandler.h"
#include "ContactListener.h"

//typedef std::vector<std::unique_ptr<Object>> GameObjects;	// maybe put in Object.h cuz also WorldMap has this
//typedef std::vector<std::unique_ptr<Static>> FixedObj;
//typedef std::vector<std::unique_ptr<Movable>> MovablesObj;

class Menu;

class Game : public GameState
{
public:
	Game(int levelNum);
	Singleton& m_resources = Singleton::instance();

	virtual GameState* handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
	virtual void draw(sf::RenderWindow& window, int r, int g, int b);
	virtual void update(sf::Time);

	void setChosenPlayer(int i);

	void setState(Menu*);

private:
	void initPlayer();
	void initWorld();

	//Player m_player;
	std::unique_ptr<Player> m_player;


	sf::Vector2f m_startLocation;
	int m_level;

	std::unique_ptr<Button>m_pauseButton;
	sf::RectangleShape m_background;
	Menu* m_menuState;
	WorldMap m_map;

	sf::CircleShape m_cir;
	
	sf::Vector2f m_prevView;

	MovablesObj m_movables;
	FixedObj m_fixed;

	//--------------BOX2D-------------
	b2Vec2 m_gravity;
	std::unique_ptr<b2World> m_world;

	ContactListener m_listner;
};