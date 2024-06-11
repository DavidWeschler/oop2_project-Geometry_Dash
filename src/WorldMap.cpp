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

	/*const sf::Color BLOCK_C = sf::Color::Black;
	const sf::Color GRAVITY_PORTAL_C = sf::Color(70, 170, 70);
	const sf::Color SPACESHIP_PORTAL_C = sf::Color::Blue;
	const sf::Color DIRECTION_PORTAL_C = sf::Color(170, 170, 70);
	const sf::Color PLAYER_C = sf::Color::Red;
	const sf::Color SPIKE_C = sf::Color::Green;
	const sf::Color ROBOT_C = sf::Color(100, 50, 100);*/

	//std::vector<std::string> m_objNames = { "Block.png", "Spike.png" , "GravityPortal.png", "SpaceShipPortal.png", "DirectionPortal.png"};


	if (color == PLAYER_C)
	{
		m_playerLocation = sf::Vector2f(posX * 60, posY * 60);
	}
	if (color == BLOCK_C)
	{	
		fixed.push_back(std::make_unique<Block>(world, m_resources.getObjTexture(0), BLOCK_C, sf::Vector2f(posX * 60, posY * 60)));
	}
	if (color == SPIKE_C)
	{
		fixed.push_back(std::make_unique<Spike>(world, m_resources.getObjTexture(1), SPIKE_C, sf::Vector2f(posX * 60, posY * 60)));
	}
	if (color == GRAVITY_PORTAL_C)
	{
		fixed.push_back(std::make_unique<GravityPortal>(world, m_resources.getObjTexture(2), SPACESHIP_PORTAL_C, sf::Vector2f(posX * 60, posY * 60)));
	}
	if (color == SPACESHIP_PORTAL_C)
	{
		fixed.push_back(std::make_unique<SpaceShipPortal>(world, m_resources.getObjTexture(3), SPACESHIP_PORTAL_C, sf::Vector2f(posX * 60, posY * 60)));
	}
	if (color == SPACESHIP_PORTAL_C)
	{
		fixed.push_back(std::make_unique<DirectionPortal>(world, m_resources.getObjTexture(4), SPACESHIP_PORTAL_C, sf::Vector2f(posX * 60, posY * 60)));
	}
}
