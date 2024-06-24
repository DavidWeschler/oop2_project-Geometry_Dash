#include "GameObj/Object.h"
#include <iostream>


Object::Object(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	:  m_color(color), m_position(position)
{
	m_shape.setSize(sf::Vector2f(60, 60));
	m_shape.setOrigin(sf::Vector2f(m_shape.getSize().x / 2, m_shape.getSize().y / 2));
	m_shape.setPosition(position);
	m_startPosition = m_shape.getPosition();
}

sf::Vector2f Object::getPosition() const
{
	return m_shape.getPosition();
}

sf::Vector2f Object::getStartPosition() const
{
	return m_startPosition;
}

sf::Color Object::getColor() const
{
	return m_color;
}

sf::FloatRect Object::getShapeGlobalBounds() const
{
	return m_shape.getGlobalBounds();
}

void Object::setPosition(sf::Vector2f position)
{
	m_shape.setPosition(position);
	m_position = position;
}

void Object::setScale(int x, int y)
{
	m_shape.setScale(x,y);
}

void Object::setColor(sf::Color color)
{
	m_color = color;
}

void Object::setFillColor(const sf::Color color)
{
	m_shape.setFillColor(color);
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

void Object::setSize(sf::Vector2f size)
{
	m_shape.setSize(size);
}

void Object::draw(sf::RenderWindow& window)
{
	if (this != NULL)		//maybe needs to go
	{
		window.draw(m_shape);
	}
}

void Object::setRotation(float angle)
{
	m_shape.setOrigin(sf::Vector2f(m_shape.getSize().x / 2, m_shape.getSize().y / 2)); // not nice. why setting from the builder doesnt work?
	m_shape.setRotation(angle);
}


void Object::setTextureRect(const sf::IntRect& rect)
{
	m_shape.setTextureRect(rect);
}