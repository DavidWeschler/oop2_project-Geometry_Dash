#include "GameObj/StaticObj/GroundJump.h"

bool GroundJump::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::GROUND_JUMP_T,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<GroundJump>(world, color, position);
	});

GroundJump::GroundJump(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody)
{
	if (color == GROUND_JUMP_C)
	{
		setTexture(10);
	}
	else if (color == GROUND_JUMP_U_C)
	{
		setTexture(14);
	}
}