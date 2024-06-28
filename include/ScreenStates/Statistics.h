#pragma once

#include "SFML/Graphics.hpp"
#include "ScreenStates/GameState.h"
#include "Singletones/GlobalConsts.h"
#include "Singletones/TexturesManger.h"
#include "ButtonCommand/NextStateCommand.h"
#include "ButtonCommand/Button.h"

class Controller;

class Statistics : public GameState
{
public:
    Statistics(Controller& controller);
    virtual void handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
    virtual void update(sf::Time) {};
    virtual void draw(sf::RenderWindow&, int, int, int);
    virtual void setSwitchMusic() {};
    virtual ~Statistics() = default;
private:
    void setBackgrounds();
    TexturesManger& m_resources = TexturesManger::instance();
    sf::RectangleShape m_background;
    sf::RectangleShape m_statsBackground;
    sf::Text m_stats;
    Button m_button;
    Controller& m_controller;
};
