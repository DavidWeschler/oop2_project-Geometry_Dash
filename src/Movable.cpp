#include "Movable.h"

Movable::Movable(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f pos)
	: Object(world, color, pos)
{
	initBox(world, b2_dynamicBody);
}


void Movable::initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType)
{
	b2FixtureDef fixtureDef;
	b2PolygonShape boxShape;
	b2BodyDef bodyDef;

	bodyDef.type = bodyType;
	bodyDef.position.Set(getPosition().x/30, getPosition().y/ 30);
	bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
	m_box = world->CreateBody(&bodyDef);

	boxShape.SetAsBox(1.0f, 1.0f);
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 5.0f;
	m_box->CreateFixture(&fixtureDef);
}
b2Vec2 Movable::getBoxPosition()
{
	return m_box->GetPosition();
}

void Movable::createFixture(b2FixtureDef* fixtureDef)
{
	m_box->CreateFixture(fixtureDef);
}
