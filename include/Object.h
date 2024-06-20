#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "FactoryFixed.h"
#include "FactoryMovables.h"
#include "Singleton.h"
#include "memory"

class Object
{
public:
	Object(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);

	virtual ~Object() = default;
	virtual void makeVirtural()=0;

	// get functions for SFML members:
	sf::Vector2f getPosition() const;
	sf::Color getColor() const;
	sf::FloatRect getShapeGlobalBounds() const;

	// set functions for SFML members:
	void setPosition(sf::Vector2f position);
	void setScale(int x, int y);
	void setColor(sf::Color color);
	void setTexture(sf::Texture& texture);
	void setTexture(int objTextureIndex);
	void setSize(int x, int y);
	void setSize(sf::Vector2f);
	void setRotation(float angle);
	void setTextureRect(const sf::IntRect& rect);
	void draw(sf::RenderWindow& window);

private:
	Object(const Object&) = delete;
	Object& operator=(const Object&) = delete;
	Singleton& m_resources = Singleton::instance();

	sf::RectangleShape m_shape;
	sf::Vector2f m_position;
	sf::Color m_color;
};