#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Singletones/TexturesManger.h"
#include "GameObj/Object.h"
#include "GameObj/MovablesObj/Player.h"
#include "GameObj/StaticObj/Static.h"
#include "Singletones/FactoryFixed.h"
#include "Singletones/FactoryMovables.h"


//typedef std::vector<std::unique_ptr<Object>> GameObjects;
typedef std::vector<std::unique_ptr<Static>> FixedObj;
typedef std::vector<std::unique_ptr<Movable>> MovablesObj;

class WorldMap
{
public:
	WorldMap(int level);
	void setWorld(int level, std::unique_ptr<b2World>& world, MovablesObj& movables, FixedObj&fixed);
	sf::Vector2f getPlayerLocation() const;

private:
	void defineObj(sf::Color color,int posX, int posY, std::unique_ptr<b2World>& world, MovablesObj& movables, FixedObj& fixed);
	ObjectTypes getObjType(sf::Color color, ObjectTypes& objType);
	Singleton& m_resources = Singleton::instance();		//maybe delete

	//Factory m_factory;

	sf::Vector2f m_playerLocation;
	sf::Image m_image;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	int m_level;
};