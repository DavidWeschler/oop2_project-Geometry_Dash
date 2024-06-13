#include "WorldMap.h"
#include "Block.h"
#include "Spike.h"
#include "GravityPortal.h"
#include "SpaceShipPortal.h"
#include "DirectionPortal.h"
#include <iostream>

WorldMap::WorldMap(int level)
{
	m_level = level;		//maybe can gos
}

void WorldMap::setWorld(int level, std::unique_ptr<b2World>& world, MovablesObj& movables, FixedObj&fixed)
{
	//m_factory.setWorld(world);
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

	if (color == ARROW_C) return;	//need to create this obj before we handle the color

	if (color == BLOCK_M_C) color = BLOCK_C;	//need to handle this case too, this is just a bandaid

	bool isFixedObj;

	ObjectTypes theObject = getObjType(color, isFixedObj);

	if (isFixedObj)
	{
		auto obj = FactoryFixed::createFixed(theObject, world, color, sf::Vector2f(posX * 60, posY * 60));
		
		if (obj)
		{
			fixed.push_back(std::move(obj)); //Note from David: we Use std::move to transfer ownership here, 
											 // because std::unique_ptr cannot be copied. 
		}
		else
		{
			//const sf::Color ARROW_C = sf::Color(105, 230, 232);
			//const sf::Color BLOCK_M_C = sf::Color(163, 73, 164);
			std::cout << "cannot create onj: " << std::to_string(color.r) << " " << std::to_string(color.g) << " " << std::to_string(color.b) << "\n";
		}

		//fixed.push_back(FactoryFixed::createFixed(theObject, world, color, sf::Vector2f(posX * 60, posY * 60)));
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
    else if (color == SPIKE_C)
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
    else if (color == DIRECTION_PORTAL_C)
    {
		return ObjectTypes::DIRECTION_PORTAL_T;
    }
    else if (color == ARROW_C)
    {
		return ObjectTypes::ARROW_T;
    }
    else
    {
		isFixed = false;
        //enemies
    }

    //else - maybe throw exception here
}
