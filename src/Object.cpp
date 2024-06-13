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
	m_bodyDef.type = bodyType;

	//if (bodyType == b2_dynamicBody) m_bodyDef.allowSleep = false; //ABSULOTLY NOT THIS FUCKS THINGS UP

	m_bodyDef.position.Set(m_shape.getPosition().x/30, m_shape.getPosition().y/ 30);
	m_bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
	m_box = world->CreateBody(&m_bodyDef);

	m_boxShape.SetAsBox(1.0f, 1.0f);
	m_fixtureDef.shape = &m_boxShape;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 7.0f;
	
	////----------------------------
	//// Custom mass properties
	//b2MassData massData;
	//massData.mass = 2.0f;
	//massData.center.Set(0.0f, 0.0f); // Center of mass relative to body's origin
	//massData.I = 1.0f; // Rotational inertia
	//m_box->SetMassData(&massData);
	////----------------------------

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
