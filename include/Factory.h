#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include "Singleton.h"
#include "Object.h"
#include "Static.h"
#include "Movable.h"
#include "Singleton.h"
#include "Block.h"
#include "Spike.h"
#include "Arrow.h"
#include "GravityPortal.h"
#include "SpaceShipPortal.h"
#include "DirectionPortal.h"

typedef std::vector<std::unique_ptr<Static>> FixedObj;
typedef std::vector<std::unique_ptr<Movable>> MovablesObj;
typedef std::unique_ptr<b2World> World;

class Factory
{
public:
	Factory();

	void createObject(sf::Color color, MovablesObj& movables, FixedObj& fixed, sf::Vector2f location);
	void setWorld(World& world);

private:
	Singleton& m_resources = Singleton::instance();
	World* m_world;
};