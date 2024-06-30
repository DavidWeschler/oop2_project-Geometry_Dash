#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Singletones/GameEnityFactory.h"
#include "Singletones/TexturesManger.h"
#include "memory"

typedef std::unique_ptr<b2World> World;

class Object
{
public:
	Object(sf::Color color, sf::Vector2f position);

	virtual ~Object() = default;

	// get functions for SFML members:
	sf::Vector2f getPosition() const;
	sf::Vector2f getStartPosition() const;
	sf::Color getColor() const;
	sf::FloatRect getShapeGlobalBounds() const;

	// set functions for SFML members:
	void setPosition(sf::Vector2f position);
	void setScale(int x, int y);
	void setColor(sf::Color color);
	void setFillColor(const sf::Color color);
	void setTexture(sf::Texture& texture);
	void setTexture(int objTextureIndex);
	void setSize(int x, int y);
	void setSize(sf::Vector2f);
	void setRotation(float angle);
	void setTextureRect(const sf::IntRect& rect);
	virtual void draw(sf::RenderWindow& window);

private:
	Object(const Object&) = delete;
	Object& operator=(const Object&) = delete;
	TexturesManger& m_resources = TexturesManger::instance();

	sf::RectangleShape m_shape;
	sf::Vector2f m_position;
	sf::Vector2f m_startPosition;
	sf::Color m_color;
};
