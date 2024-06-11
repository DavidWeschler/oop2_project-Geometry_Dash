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
	if (m_color == sf::Color::Red)
	{
		m_bodyDef.type = b2_dynamicBody;
		m_bodyDef.allowSleep = false;
	}
	else
	{
		m_bodyDef.type = b2_staticBody;
	}
	m_bodyDef.position.Set(m_shape.getPosition().x/30, m_shape.getPosition().y/ 30);
	m_bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);		//need?
	m_box = world->CreateBody(&m_bodyDef);

	m_boxShape.SetAsBox(1.0f, 1.0f);
	m_fixtureDef.shape = &m_boxShape;
	m_fixtureDef.density = 0.9f;
	m_fixtureDef.friction = 0.5f;

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



	//m_bodyDef.position.Set(m_position.x/30, m_position.y/30);
	//b2Vec2 newPos(m_position.x / 30.0f, m_position.y / 30.0f);
	//float angleRadians = 90.0f * (b2_pi / 180.0f);
	//m_box->SetTransform(newPos, angleRadians);
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
	window.draw(m_shape);
}

void Object::updatePos(sf::Time time)
{
	//m_boxPos = m_box->GetPosition();
	////m_angle = m_box->GetAngle()+ 90.0f; -ask ron (i will try to make it so that when jumping will the player will rotate. but anyway this needs to go)
	//m_shape.setPosition(m_boxPos.x, m_boxPos.y);
	////m_shape.setRotation(m_angle);

	//m_box->SetTransform(m_box->GetPosition() + b2Vec2(VELOCITY * time.asSeconds(), 0.0f), m_box->GetAngle());
	//m_shape.setPosition(m_box->GetPosition().x*30, m_box->GetPosition().y*30);
}