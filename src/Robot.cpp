#include "Robot.h"

const sf::Color robotColor = sf::Color(100, 50, 100);	//temporary, erase this

bool Robot::m_registeritRobot = FactoryMovables::registeritMovable(ObjectTypes::ROBOT_T,
	[](std::unique_ptr<b2World>& world, sf::Vector2f position) -> std::unique_ptr<Movable>
	{
		return std::make_unique<Robot>(world, position);

	});

Robot::Robot(std::unique_ptr<b2World>& world, sf::Vector2f position)
	: Enemy(world, robotColor, position, b2_dynamicBody)
{
	setTexture(12);
}
