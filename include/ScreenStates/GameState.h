#pragma once
#include <SFML/Graphics.hpp>
#include "Singletones/MusicManager.h"

class GameState 
{
public:
    virtual void handleEvent(const sf::Event&, sf::RenderWindow&) = 0;
    virtual void update(sf::Time) = 0;
    virtual void draw(sf::RenderWindow&, int, int, int) = 0;
    virtual ~GameState() = default;

    bool getReplaceMusic() const;
    void setReplaceMusic(bool state);
    void setView(sf::FloatRect rect);
    void setCenterView(float x, float y);
    sf::View getView() const;

private:
    virtual void switchMusic() =0;    

    MusicManager& m_musicHandler = MusicManager::instance();
    sf::View m_view;
    bool m_replaceMusic =true;
};