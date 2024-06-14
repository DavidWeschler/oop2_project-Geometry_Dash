#include "Button.h"

Button::Button(sf::Vector2f location, sf::Vector2f size, enum Buttons type, sf::Texture* texture)
	: m_type(type)
{
	m_shape.setSize(size);
	m_shape.setPosition(location);
	m_shape.setOrigin(size.x / 2, size.y / 2);
	m_shape.setTexture(texture);
}

void Button::setScale(float x, float y)
{
	m_shape.setScale(x, y);
}

sf::FloatRect Button::getGlobalBound() const
{
	return m_shape.getGlobalBounds();
}

enum Buttons Button::getType() const
{
	return m_type;
}

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_shape);
}

void Button::setOutlineThickness(float margin)
{
    m_shape.setOutlineThickness(margin);
}

void Button::setOutlineColor(sf::Color color)
{
    m_shape.setOutlineColor(color);
}
