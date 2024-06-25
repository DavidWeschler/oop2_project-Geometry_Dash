#pragma once
#include "GameObj\MovablesObj\Movable.h"

class Bullet : public Movable
{
public:
	Bullet(std::unique_ptr<b2World>& world, sf::Vector2f pos);	//use typdef for world
	virtual void makeVirtural() {};
	virtual void move(sf::Time time);
	virtual ~Bullet() = default;

	void setDestroy(bool state);
	bool isDestroyState() const;
private:
	static bool m_registerit;
	TexturesManger& m_resources = TexturesManger::instance();
	bool m_toDestroy;
};