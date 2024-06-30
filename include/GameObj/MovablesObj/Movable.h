#pragma once
#include "GameObj/Object.h"

class Movable : public Object
{
public:
	Movable(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f pos, sf::Vector2f boxSize, bool isBullet);
	virtual void move(sf::Time time) = 0;
	virtual bool isDestroyState() const;
	virtual ~Movable();

	void initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType, sf::Vector2f boxSize, bool isBullet);	//private?
	void createFixture(b2FixtureDef* fixtureDef);
	
	b2Vec2 getBoxPosition() const;
	b2Vec2 getLinearVelocity() const;
	float getAngle() const;
	b2Vec2 getBPosition() const;

	void setMyGravity(float g);
	void setTransform(const b2Vec2& position);
	void setLinearVelocity(const b2Vec2& vel);
	void setDestroyed(bool state);

private:
	Movable& operator=(const Movable&) = delete;
	b2Body* m_box;
	b2BodyDef m_bodyDef;
	bool m_toDestroy;
};
