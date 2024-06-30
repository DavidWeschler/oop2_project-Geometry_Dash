#pragma once
#pragma region headers
#include <SFML/Graphics.hpp>
#include "Animations/AnimationData.h"
#include "Singletones/TexturesManger.h"
#pragma endregion headers

class Robot;

class Animation
{
public:
    Animation(const AnimationData& data, Direction dir, Robot& robot);

    void direction(Direction dir);
    void update(sf::Time delta);
private:
    void update();

    TexturesManger& m_resources = TexturesManger::instance();
    const AnimationData& m_data;
    sf::Time m_elapsed = {};
    Direction m_dir = Direction::Right;
    int m_index = 0;
    Robot& m_robot;
};