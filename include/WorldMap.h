#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Singleton.h"
#include "Object.h"
#include "Player.h"

typedef std::vector<Object> GameObjects;


class WorldMap
{
public:
	WorldMap(int level);
	void setWorld(int level, std::unique_ptr<b2World>& world, GameObjects &movables, GameObjects &fixed);	//& ?
	sf::Vector2f getPlayerLocation() const;

private:
	void defineObj(sf::Color color,int posX, int posY, std::unique_ptr<b2World>& world, GameObjects &movables, GameObjects &fixed);

	Singleton& m_resources = Singleton::instance();

	sf::Vector2f m_playerLocation;
	sf::Image m_image;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	int m_level;
};