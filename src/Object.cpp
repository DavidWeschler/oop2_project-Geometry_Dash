#include "Object.h"
#include <iostream>

Object::Object()
{
	m_shape.setSize(sf::Vector2f(60, 60));
}

Object::Object(b2World& world, sf::Color color, sf::Vector2f position)
	: m_color(color), m_position(position)
{
	m_shape.setSize(sf::Vector2f(60, 60));
	m_shape.setPosition(position);


	//------box2d setup, move to func:
	m_bodyDef.type = b2_dynamicBody;
	m_box = world.CreateBody(&m_bodyDef);
	m_boxShape.SetAsBox(1.0f, 1.0f);
	m_fixtureDef.shape = &m_boxShape;
	m_fixtureDef.density = 1.0f;
	m_box->CreateFixture(&m_fixtureDef);
}

Object::Object(b2World& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
	:  m_color(color), m_position(position)
{
	m_shape.setSize(sf::Vector2f(60, 60));
	m_shape.setTexture(&texture);
	m_shape.setPosition(position);

	//------box2d setup, move to func:
	m_bodyDef.type = b2_dynamicBody;
	m_box = world.CreateBody(&m_bodyDef);
	m_boxShape.SetAsBox(1.0f, 1.0f);
	m_fixtureDef.shape = &m_boxShape;
	m_fixtureDef.density = 1.0f;
	m_box->CreateFixture(&m_fixtureDef);
}

sf::Vector2f Object::getPosition() const
{
	return m_position;
}

sf::Color Object::getColor() const
{
	return m_color;
}

void Object::setPosition(sf::Vector2f position)
{
	m_shape.setPosition(position);
	m_position = position;

	m_bodyDef.position.Set(m_position.x, m_position.y);
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

void Object::initBox(b2World& world)
{
	//------box2d setup, move to func:
	m_bodyDef.type = b2_dynamicBody;
	m_box = world.CreateBody(&m_bodyDef);
	m_boxShape.SetAsBox(1.0f, 1.0f);
	m_fixtureDef.shape = &m_boxShape;
	m_fixtureDef.density = 1.0f;
	m_box->CreateFixture(&m_fixtureDef);
}

void Object::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void Object::updatePos(sf::Time time)
{
	m_box->ApplyLinearImpulseToCenter(b2Vec2(0.0f, -5.f * time.asSeconds()), true);
	m_shape.setPosition(m_box->GetPosition().x * 60, m_box->GetPosition().y * 60);

	//sf::Vector2f pos = m_shape.getPosition();
	//m_shape.setPosition(pos.x + 5, pos.y);
}
Object::~Object() 
{
	// Destroy the body from the Box2D world
	//m_body->GetWorld()->DestroyBody(m_body);
}