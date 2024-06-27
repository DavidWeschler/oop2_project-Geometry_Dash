#include "GameObj/StaticObj/Block.h"

//remainder to future us: we can send out color directly and we dont need to recive it! 
//erase from reciving and send the const from global const --do it for EVERYONE! :(
bool Block::m_registeritBlock = GameEnityFactory<Block>::registerit(BLOCK_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Block>
	{
		return std::make_unique<Block>(world, BLOCK_C, position);
	});

bool Block::m_registeritBlock_M = GameEnityFactory<Block>::registerit(BLOCK_M_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Block>
	{
		return std::make_unique<Block>(world, BLOCK_M_C, position);
	});

bool Block::m_registeritBlock_V = GameEnityFactory<Block>::registerit(BLOCK_V_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Block>
	{
		return std::make_unique<Block>(world, BLOCK_V_C, position);
	});

Block::Block(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody)
{
	puts("blockkkk");
	//make prettier
	int texIndex = (color == BLOCK_C) ? 0 : 1;
	if (color == BLOCK_V_C)
	{
		texIndex = 13;
	}
	setTexture(texIndex);
}