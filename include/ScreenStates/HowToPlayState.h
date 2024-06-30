#pragma once
#pragma region headers
#include <vector>
#include "ScreenStates/GameState.h"
#include "ButtonCommand/Button.h"
#include "Singletones/GlobalConsts.h"
#include "Singletones/TexturesManger.h"
#include "Singletones/GlobalConsts.h"
#pragma endregion headers

class Controller;

class HowToPlayState : public GameState
{
public:
    HowToPlayState(Controller& controller);
    virtual void handleEvent(const sf::Event&, sf::RenderWindow&);
    virtual ~HowToPlayState() = default;
    virtual void update(sf::Time) {};
    virtual void draw(sf::RenderWindow&, int, int, int);
    virtual void switchMusic() {};
private:
    void setButtons(Controller& controller);
    void setBackgrounds();

    TexturesManger& m_resources = TexturesManger::instance();
    
    std::vector<Button> m_buttons;
    
    sf::RectangleShape m_background;
    sf::RectangleShape m_innerBackground;
    sf::RectangleShape m_currSlide;
    
    Controller& m_controller;

    int m_explanationIndex;
};