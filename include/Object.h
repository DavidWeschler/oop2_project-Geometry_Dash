#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "FactoryFixed.h"
#include "memory"	//for the lambda in static for factory

class Object
{
public:
	Object(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position, b2BodyType bodyType);

	virtual ~Object() = default;
	virtual void makeVirtural()=0;

	void initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType);

	sf::Vector2f getPosition() const;
	sf::Color getColor() const;
	b2Body* getBox() const;

	void setPosition(sf::Vector2f position);
	void setColor(sf::Color color);
	void setTexture(sf::Texture& texture);
	void setTexture(int objTextureIndex);
	
	void setSize(int x, int y);

	void draw(sf::RenderWindow& window);


private:
	Object(const Object&) = delete;
	Object& operator=(const Object&) = delete;
	Singleton& m_resources = Singleton::instance();

	sf::RectangleShape m_shape;
	sf::Vector2f m_position;
	sf::Color m_color;

	b2BodyDef m_bodyDef;
	b2Body* m_box;
	b2PolygonShape m_boxShape;
	b2FixtureDef m_fixtureDef;

	b2Vec2 m_boxPos;
	float m_angle;

	

	sf::RectangleShape boxSprite;
};

