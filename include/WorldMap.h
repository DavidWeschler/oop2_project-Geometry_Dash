#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Singleton.h"

//game needs him as include

typedef std::vector<GameColors> Column;
typedef std::vector<Column> Grid;

class WorldMap
{
public:
	WorldMap();
	void loadFromImagefile(const char* fileName);
	void draw(sf::RenderWindow& window);
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	Grid m_grid;
};