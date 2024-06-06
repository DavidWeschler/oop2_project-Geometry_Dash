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
	return m_shape.getPosition();
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
	//m_shape.setPosition(100, 100);

	//------box2d setup, move to func:
	m_bodyDef.type = b2_dynamicBody;
	//std::cout << m_shape.getPosition().x << " " << m_shape.getPosition().y << "\n";
	m_bodyDef.position.Set(m_shape.getPosition().x, m_shape.getPosition().y);
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
	// Set the desired constant velocity along the x-axis
	float constantVelocityX = 650.0f; // Adjust this value as needed

	// Set the linear velocity of the Box2D body to achieve the constant velocity
	m_box->SetLinearVelocity(b2Vec2(constantVelocityX, m_box->GetLinearVelocity().y));

	// Update the position of the Box2D body
	m_box->SetTransform(m_box->GetPosition() + b2Vec2(constantVelocityX * time.asSeconds(), 0.0f), m_box->GetAngle());

	// Update the position of the SFML shape based on the Box2D body position
	m_shape.setPosition(m_box->GetPosition().x, m_box->GetPosition().y);

	//std::cout << "pos: " << m_shape.getPosition().x << " " << m_shape.getPosition().y << "\n";
}

Object::~Object() 
{
	// Destroy the body from the Box2D world
	//m_body->GetWorld()->DestroyBody(m_body);
}