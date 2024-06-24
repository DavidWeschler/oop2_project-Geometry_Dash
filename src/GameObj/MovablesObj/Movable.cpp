#include "GameObj\MovablesObj\Movable.h"

Movable::Movable(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f pos, sf::Vector2f boxSize)
	: Object(world, color, pos)
{
	initBox(world, b2_dynamicBody, boxSize);
}


void Movable::initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType, sf::Vector2f boxSize)
{
	b2FixtureDef fixtureDef;
	b2PolygonShape boxShape;
	b2BodyDef bodyDef;

	bodyDef.type = bodyType;
	bodyDef.position.Set(getPosition().x / 30, getPosition().y / 30);

	bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
	boxShape.SetAsBox(boxSize.x, boxSize.y);

	m_box = world->CreateBody(&bodyDef);

	fixtureDef.shape = &boxShape;
	fixtureDef.density = 5.0f;

	m_box->CreateFixture(&fixtureDef);
}
b2Vec2 Movable::getBoxPosition() const
{
	return m_box->GetPosition();
}

void Movable::setTransform(const b2Vec2& position)
{
	m_box->SetTransform(position, m_box->GetAngle());
}

b2Vec2 Movable::getLinearVelocity() const
{
	return m_box->GetLinearVelocity();
}

void Movable::setLinearVelocity(const b2Vec2& vel)
{
	m_box->SetLinearVelocity(vel);
}

float Movable::getAngle() const
{
	return m_box->GetAngle();
}

b2Vec2 Movable::getBPosition() const
{
	return m_box->GetPosition();
}

void Movable::setMyGravity(float g)
{
	m_box->SetGravityScale(g);
}

void Movable::createFixture(b2FixtureDef* fixtureDef)
{
	m_box->CreateFixture(fixtureDef);
}
