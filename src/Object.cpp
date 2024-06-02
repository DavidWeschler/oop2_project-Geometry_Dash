#include "Object.h"

Object::Object(sf::Color color, sf::Vector2f position)
	: m_color(color), m_position(position)
{
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

void Object::draw(sf::RenderWindow& window) const
{
	window.draw(m_shape);
}
