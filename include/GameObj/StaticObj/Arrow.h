#pragma once

#include "GameObj/StaticObj/Static.h"

class Arrow : public Static
{
public:
	Arrow(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);
	virtual ~Arrow() = default;
private:
	static bool m_registerit;

};