#pragma once
#include "GameObj\MovablesObj\Movable.h"

class Bullet : public Movable
{
public:
	Bullet(World& world, sf::Color color, sf::Vector2f pos);	//use typdef for world
	virtual void move(sf::Time time);
	virtual ~Bullet() = default;
	bool isBulletDestroyed() const;
private:
	Bullet& operator=(const Bullet&) = delete;
	static bool m_registerIt;
	TexturesManger& m_resources = TexturesManger::instance();
};