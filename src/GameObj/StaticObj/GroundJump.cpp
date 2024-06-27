#include "GameObj/StaticObj/GroundJump.h"

bool GroundJump::m_registerit = GameEnityFactory<GroundJump>::registerit(GROUND_JUMP_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<GroundJump>
	{
		return std::make_unique<GroundJump>(world, GROUND_JUMP_C, position);
	});

bool GroundJump::m_registeritUp = GameEnityFactory<GroundJump>::registerit(GROUND_JUMP_U_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<GroundJump>
	{
		return std::make_unique<GroundJump>(world, GROUND_JUMP_U_C, position);
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