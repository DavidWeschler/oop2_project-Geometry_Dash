#include "Singletones/MusicManager.h"

#include <iostream>

MusicManager::MusicManager()
{
    m_currMusicIndex = 0;
	loadMusic();
}

MusicManager& MusicManager::instance()
{
	static MusicManager musicManager;
	return musicManager;
}

void MusicManager::loadMusic()
{
    for (const auto& name : m_musicNames)
    {
        auto music = std::make_unique<sf::Music>();
        if (!music->openFromFile(name))
        {
            std::cerr << "Failed to load music: " << name << std::endl;
            exit(EXIT_FAILURE);
        }
        m_backgroundMusic.push_back(std::move(music));
    }

    m_shootSound = std::make_unique<sf::Music>();
    if (!m_shootSound->openFromFile("ShootSound.ogg"))
    {
        std::cerr << "Failed to load shoot sound." << std::endl;
        exit(EXIT_FAILURE);
    }
}

sf::Music& MusicManager::getShootSound()
{
    return *m_shootSound;
}

sf::Music& MusicManager::getMusicTrack(int track)
{
    return *m_backgroundMusic[track];
}

void MusicManager::stopBackgroundMusic()
{
    m_backgroundMusic[m_currMusicIndex]->pause();
    m_backgroundMusic[m_currMusicIndex]->setPlayingOffset(sf::Time::Zero);
}

void MusicManager::setCurrMusic(int track)
{
    m_currMusicIndex = track;
}

void MusicManager::setMuteAll(bool state)
{
    m_muteAll = state;
}

bool MusicManager::getMuteAllState() const
{
    return m_muteAll;
}
