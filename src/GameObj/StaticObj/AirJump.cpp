#include "GameObj/StaticObj/AirJump.h"

bool AirJump::m_registerit = GameEnityFactory<Static>::registerit(AIR_JUMP_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<AirJump>(world, AIR_JUMP_C, position);
	});

AirJump::AirJump(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody)
{
	setSize(100, 100);
	setTexture(9);
}
