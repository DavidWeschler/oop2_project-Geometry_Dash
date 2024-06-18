#include "GroundJump.h"

bool GroundJump::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::GROUND_JUMP_T,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<GroundJump>(world, color, position);
	});

GroundJump::GroundJump(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody)
{
	setTexture(10);
}