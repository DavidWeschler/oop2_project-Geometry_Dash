#pragma once
#include "GameObj/StaticObj/Portals/Portal.h"

class GravityPortal : public Portal
{
public:
	GravityPortal(World& world, sf::Color color, sf::Vector2f position);
	virtual ~GravityPortal() = default;
private:
	static bool m_registeritGPortal;
};

