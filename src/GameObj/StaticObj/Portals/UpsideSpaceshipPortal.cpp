#include "GameObj/StaticObj/Portals/UpsideSpaceshipPortal.h"

bool UpsideSpaceshipPortal::m_registerIt = GameEnityFactory<Static>::registerit(UPSIDESPACESHIP_PORTAL_C,
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<UpsideSpaceshipPortal>(world, UPSIDESPACESHIP_PORTAL_C, position);
	});

UpsideSpaceshipPortal::UpsideSpaceshipPortal(World& world, sf::Color, sf::Vector2f position)
	: Portal(world, position)
{
	setTexture(17);
}