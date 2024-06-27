#include "GameObj/StaticObj/Portals/UpsideSpaceshipPortal.h"

bool UpsideSpaceshipPortal::m_registerit = GameEnityFactory<UpsideSpaceshipPortal>::registerit(UPSIDESPACESHIP_PORTAL_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<UpsideSpaceshipPortal>
	{
		return std::make_unique<UpsideSpaceshipPortal>(world, UPSIDESPACESHIP_PORTAL_C, position);

	});

UpsideSpaceshipPortal::UpsideSpaceshipPortal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Portal(world, color, position)
{
	setTexture(17);
}