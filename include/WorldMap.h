#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Singleton.h"
#include "Object.h"
#include "Player.h"

typedef std::vector<Object> Row;
typedef std::vector<Row> Grid;

class WorldMap
{
public:
	WorldMap(int level);
	void loadFromImagefile(int level,b2World& world);
	void drawWold(sf::RenderWindow& window);
	void setWorld(int level, b2World& world);
	sf::Vector2f getPlayerLocation() const;
private:

	void defineObj(sf::Color color, Row& row, int posX, int posY, b2World& world);
	int m_level;
	sf::Vector2f m_playerLocation;

	sf::Image m_image;
	Singleton& m_resources = Singleton::instance();

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	Grid m_grid;
};