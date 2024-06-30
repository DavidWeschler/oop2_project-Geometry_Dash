#include "ButtonCommand/Button.h"

Button::Button(sf::Vector2f location, sf::Vector2f size, sf::Texture* texture, std::unique_ptr<ButtonCommand> myCommand)
	:m_command(std::move(myCommand))
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

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_shape);
}

void Button::execute(const sf::Event& event)
{
	if (getGlobalBound().contains(event.mouseButton.x, event.mouseButton.y))
	{
		if (event.type == sf::Event::MouseButtonPressed) m_command->execute();
	}
}

void Button::setOutlineThickness(float margin)
{
    m_shape.setOutlineThickness(margin);
}

void Button::setOutlineColor(sf::Color color)
{
    m_shape.setOutlineColor(color);
}