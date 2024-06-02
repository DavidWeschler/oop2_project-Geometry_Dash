#include "WorldMap.h"

WorldMap::WorldMap()
{
	
}

void WorldMap::loadFromImagefile(const char* fileName)
{
	sf::Image image;
	image.loadFromFile(fileName);

	for (int x = 0; x < image.getSize().x; x++)
	{
		Column column;
		for (int y = 0; y < image.getSize().y; y++)
		{
			//pixelColor = m_rescources.getGameColor(image.getPixel(x, y))
			column.push_back(image.getPixel(x,y));
		}
		m_grid.push_back(column);
	}
}

void WorldMap::draw(sf::RenderWindow& window)
{
	int x = 0;
	for (const Column& column : m_grid)
	{
		int y = 0;
		for (const bool& draw : column)
		{
			
		}
	}
}
