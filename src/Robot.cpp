#include "Robot.h"

bool Robot::m_registeritRobot = FactoryMovables::registeritMovable(ObjectTypes::ROBOT_T,
	[](std::unique_ptr<b2World>& world, sf::Vector2f position) -> std::unique_ptr<Movable>
	{
		return std::make_unique<Robot>(world, position);
	});

Robot::Robot(std::unique_ptr<b2World>& world, sf::Vector2f position)
	: Enemy(world, ROBOT_C, position, b2_dynamicBody)
{
	puts("IM a robot");
	setTexture(4);// should be 12
}
