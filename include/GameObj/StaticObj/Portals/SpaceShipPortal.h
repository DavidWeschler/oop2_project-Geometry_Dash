#pragma once
#include "GameObj/StaticObj/Portals/Portal.h"

class SpaceShipPortal : public Portal
{
public:
	SpaceShipPortal(World& world, sf::Color color, sf::Vector2f position);
	virtual ~SpaceShipPortal() = default;
private:
	static bool m_registerit;
};

