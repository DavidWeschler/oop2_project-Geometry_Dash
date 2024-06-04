#pragma once

#include <SFML/Graphics.hpp>

class Object
{
public:
	Object() {};
	Object(sf::Color color, sf::Vector2f position);
	Object(sf::Texture& texture, sf::Color color, sf::Vector2f position);

	sf::Vector2f getPosition() const;
	sf::Color getColor() const;

	void setPosition(sf::Vector2f position);
	void setColor(sf::Color color);
	void setTexture(sf::Texture& texture);
	
	void setSize();

	void draw(sf::RenderWindow& window);
private:

	sf::RectangleShape m_shape;
	sf::Vector2f m_position;
	sf::Color m_color;

};

