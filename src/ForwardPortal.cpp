#include "ForwardPortal.h"

bool ForwardPortal::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::FORWARD_PORTAL_T,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<ForwardPortal>(world, color, position);

	});

ForwardPortal::ForwardPortal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Portal(world, color, position)
{
	setTexture(5);
}
