#include "WorldMap.h"

WorldMap::WorldMap(int level)
{
	m_level = level;
}

void WorldMap::loadFromImagefile(int level)
{
	m_image = m_resorces.getImage[level];

	for (int y = 0; y < image.getSize().y; y++)
	{
		Row row;
		for (int x = 0; x < image.getSize().x; x++)
		{
			row.push_back(defineObj(image.getPixel(x,y)));
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

Object* WorldMap::defineObj(sf::Color color)
{
	auto it = colorToObjectMap.find(color);
	if (it != colorToObjectMap.end()) {
		return &(it->second);
	}
	else {
		return nullptr;  // Or handle the case where the color is not found
	}
}
