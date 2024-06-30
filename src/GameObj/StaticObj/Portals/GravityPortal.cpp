#include "GameObj/StaticObj/Portals/GravityPortal.h"

bool GravityPortal::m_registeritGPortal = GameEnityFactory<Static>::registerit(GRAVITY_PORTAL_C,
	[](World& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<GravityPortal>(world, GRAVITY_PORTAL_C, position);

	});

GravityPortal::GravityPortal(World& world, sf::Color color, sf::Vector2f position)
	: Portal(world, position)
{
	setTexture(3);
}
