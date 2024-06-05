#include "WorldMap.h"
#include "Block.h"
#include "Spike.h"

WorldMap::WorldMap(int level) //needs choosen player
{
	m_level = level;
}

void WorldMap::loadFromImagefile(int level)
{
	m_image = m_resources.getImage(level-1);

	for (int y = 0; y < m_image.getSize().y; y++)
	{
		Row row;
		for (int x = 0; x < m_image.getSize().x; x++)
		{
			defineObj(m_image.getPixel(x,y), row, x, y);
		}
		m_grid.push_back(row);
	}
}

void WorldMap::drawWold(sf::RenderWindow& window)
{
	for (Row& row : m_grid) 
	{ 
		for (Object& obj : row) 
		{ 
			obj.draw(window);
		}
	}
}

void WorldMap::setWorld(int level)
{
	m_level = level;
	loadFromImagefile(m_level);
}

sf::Vector2f WorldMap::getPlayerLocation() const
{
	return m_playerLocation;
}

void WorldMap::defineObj(sf::Color color, Row& row, int posX, int posY)
{
	if (color == sf::Color::Black) 
	{	
		row.push_back(Block(m_resources.getObjTexture(0), sf::Color::Black, sf::Vector2f(posX * 60, posY * 60)));
	}
	if (color == sf::Color::Red)
	{
		m_playerLocation = sf::Vector2f(posX * 60, posY * 60);
	}
	if (color == sf::Color::Green)
	{
		row.push_back(Spike(m_resources.getObjTexture(1), sf::Color::Red, sf::Vector2f(posX * 60, posY * 60)));
	}
	//if(color== sf::Color::Green) {return }
	//if(color== sf::Color) {return } //
}
