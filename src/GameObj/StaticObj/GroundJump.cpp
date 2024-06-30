#include "GameObj/StaticObj/GroundJump.h"

bool GroundJump::m_registerIt = GameEnityFactory<Static>::registerit(GROUND_JUMP_C,
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<GroundJump>(world, GROUND_JUMP_C, position);
	});

bool GroundJump::m_registerItUp = GameEnityFactory<Static>::registerit(GROUND_JUMP_U_C,
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<GroundJump>(world, GROUND_JUMP_U_C, position);
	});

GroundJump::GroundJump(World& world, sf::Color color, sf::Vector2f position)
	: Static(world, position, b2_staticBody, sf::Vector2f(position.x / 30.f, position.y / 30.f), sf::Vector2f(1.f, 0.3f), true)
{
	if (color == GROUND_JUMP_C) setTexture(10);
	else //color == GROUND_JUMP_U_C
		setTexture(14);
}