#include "WorldMap.h"
#include "Block.h"
#include "Spike.h"

WorldMap::WorldMap(int level)
{
	m_level = level;		//maybe can gos
}

void WorldMap::setWorld(int level, std::unique_ptr<b2World>& world, GameObjects &movables, GameObjects &fixed)
{
	m_level = level;
	m_image = m_resources.getImage(level - 1);

	for (int y = 0; y < m_image.getSize().y; y++)
	{
		//Row row;
		for (int x = 0; x < m_image.getSize().x; x++)
		{
			//defineObj(m_image.getPixel(x, y), row, x, y, world);
			defineObj(m_image.getPixel(x, y), x, y, world, movables, fixed);
		}
		//m_grid.push_back(row);
	}

	//erase this:
	fixed.push_back(Block(world, m_resources.getPlayerTexture(3), sf::Color::Black, sf::Vector2f(200, 1350)));
}

sf::Vector2f WorldMap::getPlayerLocation() const
{
	return m_playerLocation;
}

//void WorldMap::defineObj(sf::Color color, Row& row, int posX, int posY, std::unique_ptr<b2World>& world)
void WorldMap::defineObj(sf::Color color, int posX, int posY, std::unique_ptr<b2World>& world, GameObjects &movables, GameObjects &fixed)
{
	if (color == sf::Color::Black) 
	{	
		fixed.push_back(Block(world, m_resources.getObjTexture(0), sf::Color::Black, sf::Vector2f(posX * 60, posY * 60)));
	}
	if (color == sf::Color::Red)
	{
		m_playerLocation = sf::Vector2f(posX * 60, posY * 60);
	}
	if (color == sf::Color::Green)
	{
		fixed.push_back(Spike(world, m_resources.getObjTexture(1), sf::Color::Red, sf::Vector2f(posX * 60, posY * 60)));
	}
	if (color == sf::Color::Blue){}
	if (color == sf::Color::Yellow){}
	if (color == sf::Color(153, 0, 153)){}	//decide what we want here
	if (color == sf::Color(255, 102, 102)){}	//decide what we want here
}
