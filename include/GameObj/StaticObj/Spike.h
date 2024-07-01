#pragma once
#include "GameObj/StaticObj/Static.h"

class Spike : public Static
{
public:
	Spike(World& world, sf::Color color, sf::Vector2f position);
	virtual ~Spike() = default;

private:
	static bool m_registerIt;
	static bool m_registerItDown;
};