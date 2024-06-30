#pragma once
#pragma region headers
#include "WorldMap.h"
#include "GameObj/StaticObj/Portals/GravityPortal.h"
#include "GameObj/StaticObj/Portals/SpaceShipPortal.h"
#include "GameObj/StaticObj/Portals/ForwardPortal.h"
#pragma endregion headers

WorldMap::WorldMap(MovablesObj& movables, FixedObj& fixed)
	:m_movables(movables), m_fixed(fixed), m_level(0)
{}

void WorldMap::setWorld(int level, World& world)
{
	if (!m_movables.empty() || !m_fixed.empty())
	{
		m_movables.clear();
		m_fixed.clear();
	}

	m_level = level;
	m_image = m_resources.getImage(m_level-1);

	for (int y = 0; y < m_image.getSize().y; y++)
	{
		for (int x = 0; x < m_image.getSize().x; x++) 
			createObj(m_image.getPixel(x, y), sf::Vector2f(x*60, y*60), world, m_movables, m_fixed);
	}
}

sf::Vector2f WorldMap::getPlayerLocation() const
{
	return m_playerLocation;
}

void WorldMap::createObj(sf::Color color, sf::Vector2f pos, World& world, MovablesObj& movables, FixedObj& fixed)
{
	if (color == PLAYER_C)
	{
		m_playerLocation = pos;
		return;
	}
	
	if (auto staticObj = GameEnityFactory<Static>::create(color, world, pos))
		fixed.emplace_back(std::move(staticObj));
	else if(auto movableObj = GameEnityFactory<Movable>::create(color, world, pos))
		movables.emplace_back(std::move(movableObj));
}