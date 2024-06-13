#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <functional>
#include "Singleton.h"
#include <Box2D/Box2D.h>

class Singleton;
class Object;
class Static;
class Movable;
class Block;
class Spike;
class Arrow;
class GravityPortal;
class SpaceShipPortal;
class DirectionPortal;


typedef std::unique_ptr<b2World> World;

typedef std::map<ObjectTypes, std::function<std::unique_ptr<Static>(std::unique_ptr<b2World>&, sf::Color, sf::Vector2f)>> FixedMap;


class FactoryFixed
{
public:
	FactoryFixed();

	static std::unique_ptr<Static> createFixed(ObjectTypes type, std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);
	static bool registeritFixed(ObjectTypes type, std::unique_ptr<Static>(*f)(std::unique_ptr<b2World>&, sf::Color, sf::Vector2f));


private:
	Singleton& m_resources = Singleton::instance();
	static FixedMap& getFixedMap();
};