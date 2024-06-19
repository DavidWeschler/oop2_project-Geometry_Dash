#include "Robot.h"

const sf::Color robotColor = sf::Color(100, 50, 100);	//temporary, erase this

bool Robot::m_registeritRobot = FactoryMovables::registeritMovable(ObjectTypes::ROBOT_T,
	[](std::unique_ptr<b2World>& world, sf::Vector2f position) -> std::unique_ptr<Movable>
	{
		return std::make_unique<Robot>(world, position);

	});

Robot::Robot(std::unique_ptr<b2World>& world, sf::Vector2f position)
	: Enemy(world, robotColor, position, b2_dynamicBody, sf::Vector2f(2, 2)), m_animation(Singleton::instance().animationData(Robot_E), Direction::Right, *this)
{
	setSize({2*60, 2*60});
}

void Robot::move(sf::Time time)
{
    if (m_aiTime.getElapsedTime().asSeconds() >= 3)
    {
		m_aiTime.restart();
		m_animation.direction(m_dir);
    }

	//sf::Vector2f position = /*robots algorithm*/;

	//m_robot.setPosition();
	m_animation.update(time);
}
