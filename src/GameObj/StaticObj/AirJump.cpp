#include "GameObj/StaticObj/AirJump.h"

bool AirJump::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::AIR_JUMP_T,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<AirJump>(world, color, position);
	});

AirJump::AirJump(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody)
{
	setSize(100, 100);
	setTexture(9);
}
