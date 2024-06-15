#pragma once

#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(sf::Vector2f, sf::Vector2f, enum Buttons, sf::Texture*);

	void setScale(float, float);
	void setOutlineThickness(float margin);
	void setOutlineColor(sf::Color color);
	sf::FloatRect getGlobalBound() const;
	enum Buttons getType() const;
	void draw(sf::RenderWindow&) const;

private:
	sf::RectangleShape m_shape;
	enum Buttons m_type;
};