#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Singleton.h"
#include "Object.h"

typedef std::vector<Object> Row;
typedef std::vector<Row> Grid;

class WorldMap
{
public:
	WorldMap(int level);
	void loadFromImagefile(int level);
	void drawWold(sf::RenderWindow& window);
	void setWorld(int level);
private:

	void defineObj(sf::Color color, Row& row);
	int m_level;
	sf::Image m_image;
	Singleton& m_resources = Singleton::instance();

	std::unordered_map<MapObjColors, Object> m_grid;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	Grid m_grid;
};