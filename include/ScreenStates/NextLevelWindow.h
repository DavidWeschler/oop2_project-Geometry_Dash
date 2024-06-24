#pragma once
#include "SFML/Graphics.hpp"
#include "ScreenStates/NextLevelWindow.h"
#include "ScreenStates/GameState.h"
#include "Singletones/GlobalConsts.h"
#include "Singletones/TexturesManger.h"
#include "ButtonCommand/Button.h"
#include "ButtonCommand/NextStateCommand.h"


class Controller;

class NextLevelWindow : public GameState
{
public:
	NextLevelWindow(Controller& controller);
    virtual void handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
    virtual void update(sf::Time) {};
    virtual void draw(sf::RenderWindow&, int, int, int);
    virtual void setSwitchMusic() {};
    virtual ~NextLevelWindow() = default;
private:
    void setButtons(Controller& controller);
    TexturesManger& m_resources = TexturesManger::instance();
    sf::RectangleShape m_background;
    std::vector<Button> m_buttons;
    Controller& m_controller;
};