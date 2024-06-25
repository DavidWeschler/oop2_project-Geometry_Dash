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
    if (!state) m_replaceMusic = state;
}
