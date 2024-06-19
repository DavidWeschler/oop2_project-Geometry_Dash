#include "Block.h"

//remainder to future us: we can send out color directly and we dont need to recive it! 
//erase from reciving and send the const from global const --do it for EVERYONE! :(
bool Block::m_registeritBlock = FactoryFixed::registeritFixed(ObjectTypes::BLOCK_T, 
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Block>(world, color, position);
	});

bool Block::m_registeritBlock_M = FactoryFixed::registeritFixed(ObjectTypes::BLOCK_M_T, 
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Block>(world, color, position);
	});

bool Block::m_registeritBlock_V = FactoryFixed::registeritFixed(ObjectTypes::BLOCK_V_T,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Block>(world, color, position);
	});

Block::Block(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody)
{
	int texIndex = (color == BLOCK_C) ? 0 : 1;
	if (color == BLOCK_V_C)
	{
		puts("yyyyayyyyy");
		texIndex = 13;
	}
	setTexture(texIndex);
}