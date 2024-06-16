#include "Object.h"
#include <iostream>
#include "Singleton.h"

Object::Object(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, b2BodyType bodyType)
	:  m_color(color), m_position(position), m_box(nullptr)
{
	m_shape.setSize(sf::Vector2f(60, 60));
	m_shape.setPosition(position);
	initBox(world, bodyType);
}

void Object::initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType)
{

	b2FixtureDef m_fixtureDef;
	b2PolygonShape m_boxShape;
	b2BodyDef m_bodyDef;

	m_bodyDef.type = bodyType;

	//if (bodyType == b2_dynamicBody) m_bodyDef.allowSleep = false;


	m_bodyDef.position.Set(m_shape.getPosition().x/30, m_shape.getPosition().y/ 30);

	m_bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);

	m_box = world->CreateBody(&m_bodyDef);
	
	if (m_color == SPACESHIP_PORTAL_C)
	{
		m_boxShape.SetAsBox(1.0f, 10.0f);
	}
	else
	{
		m_boxShape.SetAsBox(1.0f, 1.0f);
	}

	m_fixtureDef.shape = &m_boxShape;
	m_fixtureDef.density = 5.0f;
	if (m_color == ARROW_C) m_fixtureDef.isSensor = true;		//so player doesnt 'bump' into the arrow, just pass through
	if (m_color == GRAVITY_PORTAL_C) m_fixtureDef.isSensor = true;
	if (m_color == SPACESHIP_PORTAL_C) m_fixtureDef.isSensor = true;
	if (m_color == DIRECTION_PORTAL_C) m_fixtureDef.isSensor = true;
	if (m_color == SPIKE_C) m_fixtureDef.isSensor = true;
	//m_fixtureDef.friction = 0.5f;


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

void Object::setTexture(int objTextureIndex)
{
	m_shape.setTexture(&m_resources.getObjTexture(objTextureIndex));
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
