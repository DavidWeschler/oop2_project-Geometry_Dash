#pragma once

#include <SFML/Graphics.hpp>

class Object
{
public:
	Object(sf::Color color, sf::Vector2f position);

	sf::Vector2f getPosition() const;
	sf::Color getColor() const;

	void setPosition(sf::Vector2f position);
	void setColor(sf::Color color);
	void setTexture(sf::Texture& texture);

	void draw(sf::RenderWindow& window) const;
private:
	sf::RectangleShape m_shape;
	sf::Vector2f m_position;
	sf::Color m_color;

};



//-----------to singleton--------------
std::vector<std::string> m_levelNames = { "Level01.png" };

std::vector<sf::Image> m_images;

for (int i = 0; i < m_images.size(); i++)
{
	m_images.push_back(sf::Image());
	if (!(m_images[i].loadFromFile(m_levelNames[i])))
	{
		exit(EXIT_FAILURE);
	}
}