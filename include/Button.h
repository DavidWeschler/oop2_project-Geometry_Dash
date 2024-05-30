#pragma once

#include <SFML/Graphics.hpp>
#include "Singleton.h"			//ERASE!!!!

class Button
{
public:
	//Button(sf::Vector2f, sf::Vector2f, enum Buttons, sf::Shape* shape);// , sf::Texture*);

	Button(sf::Vector2f location, sf::Vector2f shapeSize, enum Buttons type, sf::CircleShape* shape, sf::Texture* texture);
	Button(sf::Vector2f location, sf::Vector2f shapeSize, enum Buttons type, sf::RectangleShape* shape, sf::Texture* texture);

	void setScale(float, float);

	sf::FloatRect getGlobalBound() const;
	enum Buttons getType() const;

	void draw(sf::RenderWindow&) const;

private:

	Singleton& m_resources = Singleton::instance();			//ERASE!!!

	sf::Shape* m_shape;

	sf::Vector2f m_location;
	enum Buttons m_type;
};