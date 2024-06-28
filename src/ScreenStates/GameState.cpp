#include "ScreenStates/GameState.h"

bool GameState::getReplaceMusic()
{
    return m_replaceMusic;
}

void GameState::setReplaceMusic(bool state)
{
    if (!(m_musicHandler.getMuteAllState()))
    {
        m_replaceMusic = state;
    }

}

void GameState::setView(sf::FloatRect rect)
{
    m_view = sf::View(rect);
}

void GameState::setCenterView(float x, float y)
{
    m_view.setCenter(x, y);
}

sf::View GameState::getView() const
{
    return m_view;
}
