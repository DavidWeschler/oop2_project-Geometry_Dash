#include "Object.h"

Object::Object(sf::Color color, sf::Vector2f position)
	: m_color(color), m_position(position)
{
	m_shape.setSize(sf::Vector2f(60, 60));
	m_shape.setPosition(position);
}

Object::Object(sf::Texture& texture, sf::Color color, sf::Vector2f position)
	:  m_color(color), m_position(position)
{
	m_shape.setSize(sf::Vector2f(60, 60));
	m_shape.setTexture(&texture);
	m_shape.setPosition(position);
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
