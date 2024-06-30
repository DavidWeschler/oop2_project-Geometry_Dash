#include "GameObj\MovablesObj\Movable.h"

Movable::Movable(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f pos, sf::Vector2f boxSize, bool isBullet)
	: Object(color, pos)//, m_boxSize(boxSize)
{
	initBox(world, b2_dynamicBody, boxSize, isBullet);
	m_toDestroy = false;
}

Movable::~Movable()
{
	if (m_toDestroy)
	{
		m_bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(nullptr);
		if (m_box) {
			m_box->GetWorld()->DestroyBody(m_box);
			m_box = nullptr;
		}
	}
}
////------------------end for bullet-----------------------------

void Movable::initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType, sf::Vector2f boxSize, bool isBullet)
{
	b2FixtureDef fixtureDef;
	b2PolygonShape boxShape;

	m_bodyDef.type = bodyType;
	m_bodyDef.position.Set(getPosition().x / 30, getPosition().y / 30);
	m_bodyDef.bullet = isBullet;
	m_bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
	m_box = world->CreateBody(&m_bodyDef);
	boxShape.SetAsBox(boxSize.x, boxSize.y);
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

void Movable::setDestroyed(bool state)
{
	m_toDestroy = state;
}

bool Movable::isDestroyState() const
{
	return m_toDestroy;
}

void Movable::createFixture(b2FixtureDef* fixtureDef)
{
	m_box->CreateFixture(fixtureDef);
}