#pragma once
#include "SFML/Graphics.hpp"
#include "NextLevelWindow.h"
#include "GameState.h"
#include "GlobalConsts.h"
#include "Singleton.h"
#include "Button.h"
#include "NextStateCommand.h"


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
    Singleton& m_resources = Singleton::instance();
    sf::RectangleShape m_background;
    std::vector<Button> m_buttons;
    Controller& m_controller;
};