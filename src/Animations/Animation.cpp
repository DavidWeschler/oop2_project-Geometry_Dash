#pragma region headers
#include "Animations/Animation.h"
#include "GameObj/MovablesObj/Robot.h"
#pragma endregion headers

Animation::Animation(const AnimationData& data, Direction dir, Robot& robot)
    : m_data(data), m_dir(dir), m_robot(robot)
{
    m_robot.setTexture(m_resources.getObjTexture(12));
    update();
}

void Animation::direction(Direction dir)
{
    m_dir = dir;
    update();
}

void Animation::update(sf::Time delta)
{
    m_elapsed += delta;
    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++m_index;
        m_index %= m_data.m_data.find(m_dir)->second.size();
        update();
    }
}

void Animation::update()
{
   m_robot.setTextureRect(m_data.m_data.find(m_dir)->second[m_index]);
}
