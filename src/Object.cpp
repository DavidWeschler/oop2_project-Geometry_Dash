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

	b2FixtureDef fixtureDef;
	b2PolygonShape boxShape;
	b2BodyDef bodyDef;

	bodyDef.type = bodyType;

	//if (bodyType == b2_dynamicBody) m_bodyDef.allowSleep = false;


	bodyDef.position.Set(m_shape.getPosition().x/30, m_shape.getPosition().y/ 30);

	bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);

	m_box = world->CreateBody(&bodyDef);
	
	if (m_color == SPACESHIP_PORTAL_C || m_color == GRAVITY_PORTAL_C || m_color == FORWARD_PORTAL_C)
	{
		boxShape.SetAsBox(1.0f, 10.0f);
	}
	else
	{
		boxShape.SetAsBox(1.0f, 1.0f);
	}

	fixtureDef.shape = &boxShape;
	fixtureDef.density = 5.0f;
	if (m_color == ARROW_C) fixtureDef.isSensor = true;		//so player doesnt 'bump' into the arrow, just pass through
	if (m_color == GRAVITY_PORTAL_C) fixtureDef.isSensor = true;
	if (m_color == SPACESHIP_PORTAL_C) fixtureDef.isSensor = true;
	if (m_color == FORWARD_PORTAL_C) fixtureDef.isSensor = true;
	if (m_color == SPIKE_C) fixtureDef.isSensor = true;
	//fixtureDef.friction = 0.5f;


	m_box->CreateFixture(&fixtureDef);

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

void Object::insertBox(std::unique_ptr<b2World>& world, int i, sf::Vector2f boxValues)
{
	b2PolygonShape boxShape;
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	bodyDef.position.Set(m_shape.getPosition().x / 30.0f, m_shape.getPosition().y / 30.0f);

	if (m_box == nullptr) {
		m_box = world->CreateBody(&bodyDef);
	}

	//boxShape.SetAsBox(4.5f / 30.0f, 2.0f / 30.0f);
	boxShape.SetAsBox(boxValues.x, boxValues.y);
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 5.0f;

	m_box->CreateFixture(&fixtureDef);

	sf::Vector2u textureSize = m_resources.getPlayerTexture(i).getSize();
	m_shape.setSize(sf::Vector2f(static_cast<float>(textureSize.x) / 3, static_cast<float>(textureSize.y) / 3));
	m_shape.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
	setTexture(m_resources.getPlayerTexture(i));
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
