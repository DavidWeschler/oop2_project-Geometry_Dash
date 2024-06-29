#pragma once
#include "SFML/Graphics.hpp"
#include "ScreenStates/NextLevelWindow.h"
#include "ScreenStates/GameState.h"
#include "Singletones/GlobalConsts.h"
#include "Singletones/TexturesManger.h"
#include "ButtonCommand/Button.h"
#include "ButtonCommand/NextStateCommand.h"


class Controller;
class Statistics;

class NextLevelWindow : public GameState
{
public:
	NextLevelWindow(Controller& controller, Statistics& stats);
    virtual void handleEvent(const sf::Event&, sf::RenderWindow&);
    virtual void update(sf::Time) {};
    virtual void draw(sf::RenderWindow&, int, int, int);
    virtual void switchMusic() {};
    virtual ~NextLevelWindow() = default;
private:
    void setButtons(Controller& controller);
    void setDisplayMembers();
    TexturesManger& m_resources = TexturesManger::instance();
    sf::RectangleShape m_background;
    sf::RectangleShape m_wellDone;
    sf::Text m_stats;
    std::vector<Button> m_buttons;
    Controller& m_controller;
    Statistics& m_levelStats;
};