#pragma once
#include "GameObj/Object.h"

class Static : public Object
{
public:
	Static(World& world, sf::Vector2f position, b2BodyType bodyType,
		   sf::Vector2f boxPosition, sf::Vector2f boxShapeSize, bool sensor);
	virtual ~Static() = default;
private:
	void initBox(World& world, b2BodyType bodyType, sf::Vector2f boxPosition, sf::Vector2f boxShapeSize, bool sensor);
	b2Body* m_box;
};