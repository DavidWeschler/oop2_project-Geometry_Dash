#pragma once
#pragma region headers
#include "SFML/Graphics.hpp"
#include "ScreenStates/GameState.h"
#include "Singletones/GlobalConsts.h"
#include "Singletones/TexturesManger.h"
#include "ButtonCommand/NextStateCommand.h"
#include "ButtonCommand/Button.h"
#pragma endregion headers

class Controller;
class Game;

class Statistics : public GameState
{
public:
    Statistics(Controller& controller, Game& game);
    virtual void handleEvent(const sf::Event&, sf::RenderWindow&);
    virtual void update(sf::Time) {};
    virtual void draw(sf::RenderWindow&, int, int, int);
    virtual void switchMusic() {};
    virtual ~Statistics() = default;

    void updatePlayerStat(PlayerStats stat, int amount);
    void updateGameStat(GameStats stat, int amount);
    int getGameStat(GameStats stat) const;
    int getPlayerStat(PlayerStats stat) const;
    std::string getTimeAsString() const;
    void clockReset();
    void setTimeStat();
private:
    void setBackgrounds();
    float calculate();
    std::string twoDigits(float value);

    TexturesManger& m_resources = TexturesManger::instance();

    sf::RectangleShape m_background;
    sf::RectangleShape m_statsBackground;
    sf::RectangleShape m_noStatsToShow;
    sf::Text m_stats;

    Controller& m_controller;
    Game& m_game;

    Button m_button;

    sf::Clock m_gameRunTime;
    sf::Time m_timeStat;

    std::vector<int> m_gameStats;
    std::vector<int> m_playerStats;
};
