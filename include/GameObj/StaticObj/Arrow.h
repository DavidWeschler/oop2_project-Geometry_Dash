#pragma once
#include "GameObj/StaticObj/Static.h"

class Arrow : public Static
{
public:
	Arrow(World& world, sf::Color color, sf::Vector2f position);
	virtual ~Arrow() = default;
private:
	static bool m_registerIt;
};