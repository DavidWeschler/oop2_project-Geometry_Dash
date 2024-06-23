#pragma once

#include <SFML/Graphics.hpp>

enum class Direction
{
    Right = 1,
    Left = -1
};

//sf::Vector2f toVector(Direction dir)
//{
//    switch (dir)
//    {
//    case Direction::Right:
//        return { 1, 0 };
//    case Direction::Left:
//        return { -1, 0 };
//    }
//    throw std::runtime_error("Unknown direction");
//}
