#include "Object.h"
#include <iostream>
#include "Singleton.h"

Object::Object(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
	:  m_color(color), m_position(position), m_box(nullptr)
{
	m_shape.setSize(sf::Vector2f(60, 60));
	m_shape.setTexture(&texture);
	m_shape.setPosition(position);

	initBox(world);
}

void Object::initBox(std::unique_ptr<b2World>& world)
{
	if (m_color == PLAYER_C || m_color == GRAVITY_PORTAL_C || m_color == SPACESHIP_PORTAL_C || m_color == DIRECTION_PORTAL_C)
	{
		m_bodyDef.type = b2_dynamicBody;
		m_bodyDef.allowSleep = false;
	}
	else
	{
		m_bodyDef.type = b2_staticBody;
	}
	m_bodyDef.position.Set(m_shape.getPosition().x/30, m_shape.getPosition().y/ 30);
	m_bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
	m_box = world->CreateBody(&m_bodyDef);

	m_boxShape.SetAsBox(1.0f, 1.0f);
	m_fixtureDef.shape = &m_boxShape;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 7.0f;

	m_box->CreateFixture(&m_fixtureDef);

	m_boxPos = m_box->GetPosition();
	m_angle = m_box->GetAngle();

}
sf::Vector2f Object::getPosition() const
{
	return m_shape.getPosition();
}

sf::Color Object::getColor() const
{
	return m_color;
}

b2Body* Object::getBox() const
{
	return m_box;
}

void Object::setPosition(sf::Vector2f position)
{
	m_shape.setPosition(position);
	m_position = position;
}

void Object::setColor(sf::Color color)
{
	m_color = color;
}

void Object::setTexture(sf::Texture& texture)
{
	m_shape.setTexture(&texture);
}

void Object::setSize(int x, int y)
{
	m_shape.setSize(sf::Vector2f(x, y));
}

void Object::draw(sf::RenderWindow& window)
{
	if (this != NULL)
	{
		window.draw(m_shape);
	}
}
