#pragma once

#include "GameObj/StaticObj/Static.h"

class LongSpike : public Static
{
public:
	LongSpike(World& world, sf::Color color, sf::Vector2f position);
	virtual ~LongSpike() = default;
	virtual void draw(sf::RenderWindow& window) override;
private:
	static bool m_registeritLong;
	static bool m_registeritDownLong;
};