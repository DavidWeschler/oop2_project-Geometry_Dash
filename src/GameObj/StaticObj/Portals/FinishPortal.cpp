#include "GameObj/StaticObj/Portals/FinishPortal.h"

bool FinishPortal::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::FINISH_PORTAL_T,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<FinishPortal>(world, color, position);

	});

FinishPortal::FinishPortal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Portal(world, color, position)
{
	setSize(3*60, 60 * 4*3);
	setTexture(11);
}
