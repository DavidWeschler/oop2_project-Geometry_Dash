#include "Block.h"

bool Block::m_registeritBlock = FactoryFixed::registeritFixed(ObjectTypes::BLOCK_T, [](std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Block>(world, texture, color, position);

	});

Block::Block(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
	: Static(world, texture, color, position)
{
	setTexture(0);
}
