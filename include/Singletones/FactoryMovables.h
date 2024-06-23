#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map> //map?? check and run cuz we use map
#include <functional>
#include "Singletones/TexturesManger.h"
#include <Box2D/Box2D.h>

class Singleton;
class Object;
class Movable;
class Player;
class Robot;

typedef std::unique_ptr<b2World> World;
typedef std::map<ObjectTypes, std::function<std::unique_ptr<Movable>(World&, sf::Vector2f)>> MovablesMap;

class FactoryMovables
{
public:
	FactoryMovables() {};

	static std::unique_ptr<Movable> createMovable(ObjectTypes type, World& world, sf::Vector2f position);
	static bool registeritMovable(ObjectTypes type, std::unique_ptr<Movable>(*f)(World&, sf::Vector2f));

private:
	static MovablesMap& getMovablesMap();
};