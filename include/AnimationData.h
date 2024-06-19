#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include "Direction.h"

struct AnimationData
{
    using ListType = std::vector<sf::IntRect>;
    using DataType = std::unordered_map<Direction, ListType>;
    DataType m_data;
};
