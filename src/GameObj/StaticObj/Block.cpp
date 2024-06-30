#include "GameObj/StaticObj/Block.h"

bool Block::m_registerItBlock = GameEnityFactory<Static>::registerit(sf::Color::Black,
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Block>(world, BLOCK_C, position);
	});

bool Block::m_registerItBlockM = GameEnityFactory<Static>::registerit(sf::Color(163, 73, 164),
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Block>(world, BLOCK_M_C, position);
	});

bool Block::m_registerItBlockV = GameEnityFactory<Static>::registerit(sf::Color(29, 07, 98),
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Block>(world, BLOCK_V_C, position);
	});

Block::Block(World& world, sf::Color color, sf::Vector2f position)
	: Static(world, position, b2_staticBody, sf::Vector2f(position.x / 30.f, position.y / 30.f), sf::Vector2f(1.f, 1.f), false)
{
	int texIndex = (color == BLOCK_C) ? 0 : 1;
	if (color == BLOCK_V_C) texIndex = 13;
	
	setTexture(texIndex);
}