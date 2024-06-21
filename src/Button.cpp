#include "Button.h"

//Button::Button(sf::Vector2f location, sf::Vector2f size, enum Buttons type, sf::Texture* texture)	//neds to go
//	: m_type(type)
//{
//	m_shape.setSize(size);
//	m_shape.setPosition(location);
//	m_shape.setOrigin(size.x / 2, size.y / 2);
//	m_shape.setTexture(texture);
//}

Button::Button(sf::Vector2f location, sf::Vector2f size, Buttons type, sf::Texture* texture, std::unique_ptr<ButtonCommand> myCommand)
	: m_type(type), m_command(std::move(myCommand))
{
	m_shape.setSize(size);
	m_shape.setPosition(location);
	m_shape.setOrigin(size.x / 2, size.y / 2);
	m_shape.setTexture(texture);
}

//void Button::setScale(float x, float y)
//{
//
//	m_shape.setScale(x, y);
//}

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

void Button::execute(const sf::Event& event)
{
	if (getGlobalBound().contains(event.mouseButton.x, event.mouseButton.y))
	{
		m_shape.setScale(1.1f, 1.1f);
		if (event.type == sf::Event::MouseButtonPressed)
		{
			m_command->execute();
		}
		return;
	}
	m_shape.setScale(1.f, 1.f);
}

void Button::setOutlineThickness(float margin)
{
    m_shape.setOutlineThickness(margin);
}

void Button::setOutlineColor(sf::Color color)
{
    m_shape.setOutlineColor(color);
}
