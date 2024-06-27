#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Singletones/TexturesManger.h"
#include "GameObj/Object.h"
#include "GameObj/MovablesObj/Player.h"
#include "GameObj/StaticObj/Static.h"

#include "Singletones/GameEnityFactory.h"

typedef std::vector<std::unique_ptr<Static>> FixedObj;
typedef std::vector<std::unique_ptr<Movable>> MovablesObj;

class WorldMap
{
public:
	WorldMap(MovablesObj& movables, FixedObj& fixed);
	void setWorld(int level, std::unique_ptr<b2World>& world);
	sf::Vector2f getPlayerLocation() const;

private:
	void createObj(sf::Color color, sf::Vector2f pos, std::unique_ptr<b2World>& world, MovablesObj& movables, FixedObj& fixed);
	TexturesManger& m_resources = TexturesManger::instance();		//maybe delete

	MovablesObj& m_movables;
	FixedObj& m_fixed;

	sf::Vector2f m_playerLocation;
	sf::Image m_image;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	int m_level;
};