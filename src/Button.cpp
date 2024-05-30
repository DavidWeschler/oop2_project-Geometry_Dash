#include "Button.h"

//Button::Button(sf::Vector2f location, sf::Vector2f shapeSize, enum Buttons type, sf::Shape* shape)//, sf::Texture* aTexture)
//	: m_location(location),	m_type(type), m_shape(shape)
//{
//
//
//	//m_shape.setSize(shapeSize);
//	/*m_shape.setScale(shapeSize);
//	m_shape.setOrigin(shapeSize.x / 2, shapeSize.y / 2);
//	m_shape.setPosition(m_location);
//	m_shape.setTexture(&m_resources.getButtonTextures(0));*/
//
//	//m_shape->setScale(shapeSize);
//	//m_shape->setOrigin(shapeSize.x / 2, shapeSize.y / 2);
//	//m_shape->setPosition(m_location);
//	//m_shape->setTexture(&m_resources.getButtonTextures(0));
//
//}

Button::Button(sf::Vector2f location, sf::Vector2f shapeSize, enum Buttons type, sf::CircleShape* shape)
    : m_location(location), m_type(type), m_shape(shape)
{
    sf::CircleShape* circleShape = dynamic_cast<sf::CircleShape*>(m_shape);
    circleShape->setRadius(shapeSize.x); // Assuming shapeSize.x contains the radius of the circle
    m_shape->setOrigin(shapeSize.x, shapeSize.x);
    m_shape->setPosition(m_location);
}

Button::Button(sf::Vector2f location, sf::Vector2f shapeSize, enum Buttons type, sf::RectangleShape* shape)
    : m_location(location), m_type(type), m_shape(shape)
{
    sf::RectangleShape* rectShape = dynamic_cast<sf::RectangleShape*>(m_shape);
    rectShape->setSize(shapeSize);
    m_shape->setOrigin(shapeSize.x / 2, shapeSize.y / 2);
    m_shape->setPosition(m_location);
}

void Button::setScale(float x, float y)
{
	m_shape->setScale(x, y);
}

sf::FloatRect Button::getGlobalBound() const
{
	//return m_shape.getGlobalBounds();
	return m_shape->getGlobalBounds();
}

enum Buttons Button::getType() const
{
	return m_type;
}

void Button::draw(sf::RenderWindow& window) const
{
	//window.draw(m_shape);
	window.draw(*m_shape);
}