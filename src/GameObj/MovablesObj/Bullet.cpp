#include "GameObj/MovablesObj/Bullet.h"

bool Bullet::m_registerIt = GameEnityFactory<Movable>::registerit(BULLET_C,
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Movable>
	{
		return std::make_unique<Bullet>(world, BULLET_C, position);
	});

Bullet::Bullet(World& world, sf::Color, sf::Vector2f pos)
	: Movable(world, pos, sf::Vector2f(0.1, 0.1), true)
{
	setSize({ 30, 30 });
	int bulletTextNum = rand() % 8;
	setTexture(m_resources.getBulletTexture(bulletTextNum));
	setMyGravity(0);
}

void Bullet::move(sf::Time time)
{
	auto distance = BULLET_VELOCITY * time.asSeconds();
	b2Vec2 newPos = (getBPosition() + b2Vec2(distance, 0.0f));
	setTransform(newPos);	
	setPosition(sf::Vector2f(getBoxPosition().x * 30, getBoxPosition().y * 30));

	if (getPosition().x > getStartPosition().x + 1500)
		setDestroyed(true);
}

bool Bullet::isBulletDestroyed() const
{
	return isDestroyState();
}