#include "WorldMap.h"
#include "Block.h"

WorldMap::WorldMap(int level) //needs choosen player
{
	m_level = level;
}

void WorldMap::loadFromImagefile(int level)
{
	m_image = m_resources.getImage(level);

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
	int x = 0;
	for (const Row& row : m_grid)
	{
		int y = 0;
		for (const bool& draw : row)
		{
			//acually draw
		}
	}
}

void WorldMap::setWorld(int level)
{
	m_level = level;
	loadFromImagefile(m_level);
}

void WorldMap::defineObj(sf::Color color, Row& row, int posX, int posY)
{
	if (color == sf::Color::Black) { row.push_back(Block(m_resources.getPlayerTexture(0), sf::Color::Black, posX *60, posY *60) };
	if (color == sf::Color::Red) { return };
	//if(color== sf::Color::Green) {return }
	//if(color== sf::Color) {return }
}
