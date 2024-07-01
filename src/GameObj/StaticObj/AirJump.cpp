#include "GameObj/StaticObj/AirJump.h"

bool AirJump::m_registerIt = GameEnityFactory<Static>::registerit(AIR_JUMP_C,
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<AirJump>(world, AIR_JUMP_C, position);
	});

AirJump::AirJump(World& world, sf::Color, sf::Vector2f position)
	: Static(world, position, b2_staticBody, sf::Vector2f(position.x / 30.f, position.y / 30.f), sf::Vector2f(2.f, 1.5f), true)
{
	setSize(100, 100);
	setTexture(9);
}