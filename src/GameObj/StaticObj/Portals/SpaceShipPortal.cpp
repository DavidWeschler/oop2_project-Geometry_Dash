#include "GameObj/StaticObj/Portals/SpaceShipPortal.h"

bool SpaceShipPortal::m_registerit = GameEnityFactory<SpaceShipPortal>::registerit(SPACESHIP_PORTAL_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<SpaceShipPortal>
	{
		return std::make_unique<SpaceShipPortal>(world, SPACESHIP_PORTAL_C, position);

	});

SpaceShipPortal::SpaceShipPortal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Portal(world, color, position)
{
	setTexture(4);
}
