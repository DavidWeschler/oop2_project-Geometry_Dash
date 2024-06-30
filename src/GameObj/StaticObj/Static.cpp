#include "GameObj/StaticObj/Static.h"

Static::Static(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, b2BodyType bodyType,
				sf::Vector2f boxPosition, sf::Vector2f boxShapeSize, bool sensor)
	: Object(color, position)
{
	initBox(world, bodyType, boxPosition, boxShapeSize, sensor);
}

void Static::initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType, 
	sf::Vector2f boxPosition, sf::Vector2f boxShapeSize, bool sensor)
{
	b2FixtureDef fixtureDef;
	b2PolygonShape boxShape;
	b2BodyDef bodyDef;

	bodyDef.type = bodyType;
	bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
	bodyDef.position.Set(boxPosition.x, boxPosition.y);

	boxShape.SetAsBox(boxShapeSize.x, boxShapeSize.y);

	fixtureDef.isSensor = sensor;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 5.0f;

	m_box = world->CreateBody(&bodyDef);
	m_box->CreateFixture(&fixtureDef);
}