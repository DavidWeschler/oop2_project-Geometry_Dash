#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Singleton.h"
//#include "Object.h"

//game needs him as include

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
	int m_level;
	sf::Image m_image;
	Object* defineObj(sf::Color color);

	std::unordered_map<MapObjColors, Object> m_grid;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	Grid m_grid;
};