#pragma once

#include <SFML/Graphics.hpp>

struct GameState 
{
    virtual GameState* handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time) = 0;
    virtual void update(sf::Time) = 0;
    virtual void draw(sf::RenderWindow&, int, int, int) = 0;
    virtual ~GameState() = default;

    sf::View _view;
};