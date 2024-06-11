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
	m_factory.setWorld(world);
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

void WorldMap::defineObj(sf::Color color, int posX, int posY, std::unique_ptr<b2World>& world/*can go i think*/, MovablesObj& movables, FixedObj& fixed)
{
	if (color == PLAYER_C)
	{
		m_playerLocation = sf::Vector2f(posX * 60, posY * 60);
		return;
	}
	m_factory.createObject(color, movables, fixed, sf::Vector2f(posX * 60, posY * 60));
}
