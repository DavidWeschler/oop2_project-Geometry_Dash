#include "Animation.h"


const auto AnimationTime = sf::seconds(0.3f);

Animation::Animation(const AnimationData& data, Direction dir, sf::RectangleShape& sprite)
    : m_data(data), m_dir(dir), m_sprite(sprite)
{
    m_sprite.setTexture(&m_resources.getObjTexture(12));
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
    m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_index]);
}
