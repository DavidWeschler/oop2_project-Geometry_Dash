#pragma once

#include "GameObj/StaticObj/Static.h"

class AirSpike : public Static
{
public:
	AirSpike(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);

	virtual void makeVirtural() {};
	virtual void draw(sf::RenderWindow& window) override;
private:
	static bool m_registerit;
	int m_rotation;
};