#include "GameObj/StaticObj/Portals/ForwardPortal.h"

bool ForwardPortal::m_registerit = GameEnityFactory<Static>::registerit(FORWARD_PORTAL_C,
	[](World& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<ForwardPortal>(world, FORWARD_PORTAL_C, position);

	});

ForwardPortal::ForwardPortal(World& world, sf::Color color, sf::Vector2f position)
	: Portal(world, position)
{
	setTexture(5);
}
