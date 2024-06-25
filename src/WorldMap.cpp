#include "WorldMap.h"
#include "GameObj/StaticObj/Portals/GravityPortal.h"
#include "GameObj/StaticObj/Portals/SpaceShipPortal.h"
#include "GameObj/StaticObj/Portals/ForwardPortal.h"
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

	ObjectTypes objType;

	ObjectTypes theObject = getObjType(color, objType);

	if (objType== ObjectTypes::FIXED_T)
	{
		auto obj = FactoryFixed::createFixed(theObject, world, color, sf::Vector2f(posX * 60, posY * 60));
		fixed.push_back(std::move(obj)); //we Use std::move to transfer ownership here, because std::unique_ptr cannot be copied. 
	}
	else if(objType == ObjectTypes::MOVABLE_T)
	{
		auto obj = FactoryMovables::createMovable(theObject, world, sf::Vector2f(posX * 60, posY * 60));
		movables.push_back(std::move(obj)); //we Use std::move to transfer ownership here, because std::unique_ptr cannot be copied. 
	}
}

ObjectTypes WorldMap::getObjType(sf::Color color, ObjectTypes& objType)
{
	if (color == BLOCK_C)
    {
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::BLOCK_T;
    }
    else if (color == BLOCK_M_C)
    {
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::BLOCK_M_T;
    }
	else if (color == BLOCK_V_C)
	{
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::BLOCK_V_T;
	}
    else if (color == SPIKE_C || color == DOWN_SPIKE_C || color == LONG_SPIKE_C || color == DOWN_LONG_SPIKE_C)
    {
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::SPIKE_T;
    }
	else if (color == AIR_SPIKE_C)
	{
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::AIRSPIKE_T;
	}
    else if (color == GRAVITY_PORTAL_C)
    {
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::GRAVITY_PORTAL_T;
    }
    else if (color == SPACESHIP_PORTAL_C)
    {
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::SPACESHIP_PORTAL_T;
    }
    else if (color == FORWARD_PORTAL_C)
    {
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::FORWARD_PORTAL_T;
    }
	else if (color == UPSIDESPACESHIP_PORTAL_C)
	{
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::UPSIDESPACESHIP_T;
	}
	else if (color == FINISH_PORTAL_C)
	{
		objType = ObjectTypes::FIXED_T;
		return  ObjectTypes::FINISH_PORTAL_T;
	}
    else if (color == ARROW_C)
    {
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::ARROW_T;
    }
	else if (color == AIR_JUMP_C)
	{
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::AIR_JUMP_T;
	}
	else if (color == GROUND_JUMP_C || color == GROUND_JUMP_U_C)
	{
		objType = ObjectTypes::FIXED_T;
		return ObjectTypes::GROUND_JUMP_T;
	}
    else if(color==ROBOT_C)
    {
		objType = ObjectTypes::MOVABLE_T;
		return ObjectTypes::ROBOT_T;
    }
	else if (color == BULLET_C)		//NO NEED FOR THIS! ERASEEEE
	{
		objType = ObjectTypes::MOVABLE_T;
		return ObjectTypes::BULLET_T;
	}
	else
	{
		objType = ObjectTypes::ERROR_T;
	}

    //else - maybe throw exception here
}
