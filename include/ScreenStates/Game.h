#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <random>
#include <ctime>
#include <string>
#include <memory> 
#include "GameObj/MovablesObj/Player.h"
#include "GameObj/StaticObj/Static.h"
#include "GameObj/MovablesObj/Bullet.h"
#include "Singletones/TexturesManger.h"
#include "Singletones/MusicManager.h"
#include "ButtonCommand/Button.h"
#include "ScreenStates/GameState.h"
#include "WorldMap.h"
#include "CollisionHandler.h"
#include "ContactListener.h"

class Menu;
class Controller;

class Game : public GameState
{
public:
	Game(Controller& controller);
	virtual ~Game();
	virtual void handleEvent(const sf::Event& event, sf::RenderWindow&);
	virtual void draw(sf::RenderWindow& window, int r, int g, int b);
	virtual void update(sf::Time);
	void setChosenPlayer(int i);
	int getGameStat(GameStats stat) const;
	int getPlayerStat(PlayerStats stat) const;

private:
	virtual void switchMusic();
	void setButton(Controller& controller);
	void setPrompt();
	void setLevelsOrder();
	void initPlayer();
	void initWorld();
	void moveEnemy(sf::Time time);
	void moveBullets(sf::Time time);
	void handleRestart();
	void handleDeletionBullets();
	void fireBullet();
	void resetAttempt();
	void adjustViewOffset(int& offSet);
	void drawWorldObj(sf::RenderWindow& window);
	void drawPrompts(sf::RenderWindow& window);
	void handleWin();

	TexturesManger& m_resources = TexturesManger::instance();
	MusicManager& m_musicHandler = MusicManager::instance();
	Controller& m_controller;
	Menu* m_menuState;
	WorldMap m_map;
	MovablesObj m_movables;
	FixedObj m_fixed;

	std::unique_ptr<Player> m_player;
	std::queue<int> m_levelIndex;
	std::unique_ptr<Button>m_exitButton;
	std::unique_ptr<b2World> m_world;
	b2Vec2 m_gravity;
	ContactListener m_listener;

	sf::Vector2f m_startLocation;
	sf::RectangleShape m_background;
	sf::RectangleShape m_prompt;
	sf::Clock m_promptDisplay;
	sf::Clock m_bulletCooldown;
	sf::Time m_promptTime;

	int m_level;
	int m_musicTrack;
	std::vector<int> m_stats;

	//------------bullets---------------------------
	std::vector<std::unique_ptr<Movable>> m_bullets;
};