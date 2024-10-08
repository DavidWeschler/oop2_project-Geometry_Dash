#include "GameObj/MovablesObj/Robot.h"

bool Robot::m_registerItRobot = GameEnityFactory<Movable>::registerit(ROBOT_C,
	[](World& world, sf::Color, sf::Vector2f position) -> std::unique_ptr<Movable>
	{
		return std::make_unique<Robot>(world, ROBOT_C, position);
	});

Robot::Robot(World& world, sf::Color, sf::Vector2f pos)
	: Enemy(world, pos, sf::Vector2f(1, 2.9)), m_animation(TexturesManger::instance().animationData(Robot_E), Direction::Right, *this)
{
	m_way = 1;
	setSize({2*60, 2*60});
}

void Robot::move(sf::Time time)
{
	b2Vec2 boxPos = getBoxPosition();
    if (m_aiTime.getElapsedTime().asSeconds() >= 3)
    {
		m_aiTime.restart();
		m_animation.direction(m_dir);
    }
	m_animation.update(time);

	setTransform(boxPos + b2Vec2(ENEMY_VELOCITY * m_way *time.asSeconds(), 0.0f));
	setPosition(sf::Vector2f(boxPos.x * 30, boxPos.y * 30));
}

void Robot::setDir()
{
	m_way *= -1;
	setScale(m_way, 1);
}
