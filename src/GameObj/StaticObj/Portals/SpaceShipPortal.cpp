#include "GameObj/StaticObj/Portals/SpaceShipPortal.h"

bool SpaceShipPortal::m_registerit = GameEnityFactory<Static>::registerit(SPACESHIP_PORTAL_C,
	[](World& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<SpaceShipPortal>(world, SPACESHIP_PORTAL_C, position);

	});

SpaceShipPortal::SpaceShipPortal(World& world, sf::Color color, sf::Vector2f position)
	: Portal(world, position)
{
	setTexture(4);
}
