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
	void drawWorld(sf::RenderWindow& window);
	void setWorld(int level, std::unique_ptr<b2World>& world);
	sf::Vector2f getPlayerLocation() const;

private:
	void defineObj(sf::Color color, Row& row, int posX, int posY, std::unique_ptr<b2World>& world);

	Singleton& m_resources = Singleton::instance();

	sf::Vector2f m_playerLocation;
	sf::Image m_image;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	Grid m_grid;

	int m_level;
};