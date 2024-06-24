#pragma once

#include <SFML/Graphics.hpp>
#include "Singletones/MusicManager.h"

class GameState 
{
public:
    virtual void handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time) = 0;
    virtual void update(sf::Time) = 0;
    virtual void draw(sf::RenderWindow&, int, int, int) = 0;
    virtual ~GameState() = default;

    bool getReplaceMusic();
    void setReplaceMusic(bool state);
    sf::View _view;
private:
    MusicManager& m_musicHandler = MusicManager::instance();
    virtual void setSwitchMusic() =0;
    bool m_replaceMusic =true;
};