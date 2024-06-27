#include "GameObj/StaticObj/Portals/FinishPortal.h"

bool FinishPortal::m_registerit = GameEnityFactory<FinishPortal>::registerit(FINISH_PORTAL_C,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<FinishPortal>
	{
		return std::make_unique<FinishPortal>(world, FINISH_PORTAL_C, position);

	});

FinishPortal::FinishPortal(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Portal(world, color, position)
{
	setSize(3*60, 60 * 4*3);
	setTexture(11);
}
