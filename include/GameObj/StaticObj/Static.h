#pragma once

#include "GameObj/Object.h"

class Static : public Object
{
public:
	Static(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, b2BodyType bodyType,
		sf::Vector2f boxPosition, sf::Vector2f boxShapeSize, bool sensor);
	virtual ~Static() = default;

private:
	void initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType, sf::Vector2f boxPosition, sf::Vector2f boxShapeSize, bool sensor);
	b2Body* m_box;
};