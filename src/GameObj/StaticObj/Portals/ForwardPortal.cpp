#include "GameObj/StaticObj/Portals/ForwardPortal.h"

bool ForwardPortal::m_registerit = GameEnityFactory<ForwardPortal>::registerit(FORWARD_PORTAL_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<ForwardPortal>
	{
		return std::make_unique<ForwardPortal>(world, FORWARD_PORTAL_C, position);

	});

ForwardPortal::ForwardPortal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Portal(world, color, position)
{
	setTexture(5);
}
