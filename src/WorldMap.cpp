#include "WorldMap.h"
#include "Block.h"
#include "Spike.h"
#include "GravityPortal.h"
#include "SpaceShipPortal.h"
#include "ForwardPortal.h"
#include <iostream>

WorldMap::WorldMap(int level)
{
	m_level = level;		//maybe can gos
}

void WorldMap::setWorld(int level, std::unique_ptr<b2World>& world, MovablesObj& movables, FixedObj&fixed)
{
	m_level = level;
	m_image = m_resources.getImage(level - 1);

	for (int y = 0; y < m_image.getSize().y; y++)
	{
		for (int x = 0; x < m_image.getSize().x; x++)
		{
			defineObj(m_image.getPixel(x, y), x, y, world, movables, fixed);
		}
	}
}

sf::Vector2f WorldMap::getPlayerLocation() const
{
	return m_playerLocation;
}

void WorldMap::defineObj(sf::Color color, int posX, int posY, std::unique_ptr<b2World>& world, MovablesObj& movables, FixedObj& fixed)
{
	if (color == PLAYER_C)
	{
		m_playerLocation = sf::Vector2f(posX * 60, posY * 60);
		return;
	}

	bool isFixedObj;

	ObjectTypes theObject = getObjType(color, isFixedObj);

	if (isFixedObj)
	{
		auto obj = FactoryFixed::createFixed(theObject, world, color, sf::Vector2f(posX * 60, posY * 60));
		fixed.push_back(std::move(obj)); //we Use std::move to transfer ownership here, because std::unique_ptr cannot be copied. 

	}
	else
	{
		//create Movable
	}
}

ObjectTypes WorldMap::getObjType(sf::Color color, bool& isFixed)
{
	isFixed = true;
	if (color == BLOCK_C)
    {
		return ObjectTypes::BLOCK_T;
    }
    else if (color == BLOCK_M_C)
    {
		return ObjectTypes::BLOCK_M_T;
    }
    else if (color == SPIKE_C || color == DOWN_SPIKE_C || color == AIR_SPIKE_C)
    {
		return ObjectTypes::SPIKE_T;
    }
    else if (color == GRAVITY_PORTAL_C)
    {
		return ObjectTypes::GRAVITY_PORTAL_T;
    }
    else if (color == SPACESHIP_PORTAL_C)
    {
		return ObjectTypes::SPACESHIP_PORTAL_T;
    }
    else if (color == FORWARD_PORTAL_C)
    {
		return ObjectTypes::FORWARD_PORTAL_T;
    }
    else if (color == ARROW_C)
    {
		return ObjectTypes::ARROW_T;
    }
	else if (color == AIR_JUMP_C)
	{
		return ObjectTypes::AIR_JUMP_T;
	}
	else if (color == GROUND_JUMP_C)
	{
		return ObjectTypes::GROUND_JUMP_T;
	}
    else
    {
		isFixed = false;
        //enemies
    }

    //else - maybe throw exception here
}
