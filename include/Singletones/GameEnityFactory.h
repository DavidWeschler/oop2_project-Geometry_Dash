#pragma once
#pragma region headers

#include <SFML/Graphics.hpp>
#include <memory>
#include <map>
#include <functional>
#include "Singletones/TexturesManger.h"
#include <Box2D/Box2D.h>

#pragma region headers

class TexturesManger;
class Object;
class Static;
class Block;
class Spike;
class AirSpike;
class Arrow;
class GravityPortal;
class SpaceShipPortal;
class DirectionPortal;
class Object;
class Movable;
class Player;
class Robot;

struct ColorComp
{
	bool operator()(const sf::Color& colorA, const sf::Color& colorB) const
	{
		if (colorA.r != colorB.r) return colorA.r < colorB.r;
		if (colorA.g != colorB.g) return colorA.g < colorB.g;
		return colorA.b < colorB.b;
	}
};

typedef std::unique_ptr<b2World> World;

template<typename T>
class GameEnityFactory
{
public:
	GameEnityFactory() {};
	~GameEnityFactory() = default;

	typedef std::map<sf::Color, std::function<std::unique_ptr<T>(World&, sf::Color, sf::Vector2f)>, ColorComp> Map;

	static std::unique_ptr<T> create(sf::Color color, World& world, sf::Vector2f position);
	static bool registerit(const sf::Color& color, std::unique_ptr<T>(*f)(World&, sf::Color, sf::Vector2f));

private:
	static Map& getMap() 
	{
		static Map m_map;
		return m_map;
	}
};

template<typename T>
inline std::unique_ptr<T> GameEnityFactory<T>::create(sf::Color color, World& world, sf::Vector2f position)
{
	auto it = getMap().find(color);
	if (it == getMap().end()) return nullptr;	
	return it->second(world, color, position);
}

template<typename T>
bool GameEnityFactory<T>::registerit(const sf::Color& color, std::unique_ptr<T>(*f)(World&, sf::Color, sf::Vector2f))
{
	getMap().emplace(color, std::move(f));
	return true;
}