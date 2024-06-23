#pragma once

#include "GameObj/StaticObj/Static.h"

class GroundJump : public Static
{
public:
	GroundJump(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);
	virtual void makeVirtural() {};

private:
	static bool m_registerit;
};