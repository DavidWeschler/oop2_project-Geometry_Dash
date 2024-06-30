#pragma once

#pragma region headers

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include "Animations/Direction.h"

#pragma endregion headers

struct AnimationData
{
    using ListType = std::vector<sf::IntRect>;
    using DataType = std::unordered_map<Direction, ListType>;
    DataType m_data;
};
