#pragma once

#include "ScreenStates/GameState.h"
#include "ButtonCommand/Button.h"
#include "Singletones/GlobalConsts.h"
#include "Singletones/TexturesManger.h"
#include "Singletones/GlobalConsts.h"
#include <vector>

class Controller;

class HowToPlayState : public GameState
{
public:
    HowToPlayState(Controller& controller);
    virtual void handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
    virtual void update(sf::Time) {};
    virtual void draw(sf::RenderWindow&, int, int, int);
    virtual void setSwitchMusic() {};
    virtual ~HowToPlayState() = default;
private:
    void setButtons(Controller& controller);
    TexturesManger& m_resources = TexturesManger::instance();
    std::vector<Button> m_buttons;
    sf::RectangleShape m_background;
    sf::RectangleShape m_innerBackground;
    sf::RectangleShape m_currSlide;
    Controller& m_controller;


    //std::vector<sf::RectangleShape> m_explanations;

    int m_explanationIndex;
};