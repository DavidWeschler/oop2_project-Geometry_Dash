#include "GameObj/MovablesObj/Bullet.h"

bool Bullet::m_registerit = FactoryMovables::registeritMovable(ObjectTypes::BULLET_T,
	[](std::unique_ptr<b2World>& world, sf::Vector2f position) -> std::unique_ptr<Movable>
	{
		return std::make_unique<Bullet>(world, position);

	});

Bullet::Bullet(std::unique_ptr<b2World>& world, sf::Vector2f pos)
	: Movable(world, BULLET_C, pos, sf::Vector2f(0.1, 0.1))

{
	setSize({ 30, 30 });
	int bulletTextNum = rand() % 8;
	setTexture(m_resources.getBulletTexture(bulletTextNum));
	m_toDestroy = false;

	setMyGravity(0);
}

void Bullet::move(sf::Time time)
{
	auto distance = BULLET_VELOCITY * time.asSeconds();
	b2Vec2 newPos = (getBPosition() + b2Vec2(distance, 0.0f));
	setTransform(newPos);	
	setPosition(sf::Vector2f(getBoxPosition().x * 30, getBoxPosition().y * 30));
}

void Bullet::setDestroy(bool state)
{
	m_toDestroy = state;
}

bool Bullet::isDestroyState() const
{
	return m_toDestroy;
}
