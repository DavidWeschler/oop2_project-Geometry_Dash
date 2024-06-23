#include "Singletones/MusicManager.h"

#include <iostream>

MusicManager::MusicManager()
{
    m_backgroundMusicPlaying = true;
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
			exit(EXIT_FAILURE);
		}
		m_backgroundMusic.push_back(std::move(music));
	}
}

void MusicManager::setBackgroundMusic()
{
    m_backgroundMusicPlaying = !m_backgroundMusicPlaying;

    //if (!m_backgroundMusicPlaying)
    //{
    //    m_backgroundMusicPlaying = true;
    //    // Start the thread to play background music
    //    stopThread = false; // Reset the stop flag
    //    backgroundMusicThread = std::thread([this]() {
    //        sf::Music& music = *m_backgroundMusic[0]; // Assuming you want to play the first music in the vector
    //        while (m_backgroundMusicPlaying)
    //        {
    //            if (music.getStatus() != sf::Music::Playing)
    //            {
    //                music.play();
    //                music.setVolume(3);
    //            }
    //            // Wait for the signal to stop or timeout
    //            std::unique_lock<std::mutex> lock(mtx);
    //            cv.wait_for(lock, std::chrono::seconds(1), [this]() { return stopThread; });
    //            if (stopThread)
    //            {
    //                music.stop();
    //                break;
    //            }
    //        }
    //        });
    //}
    //else {
    //    stopBackgroundMusic();
    //}
}

//void MusicManager::stopBackgroundMusic()
//{
//    //if (m_backgroundMusicPlaying)
//    //{
//    //    m_backgroundMusicPlaying = false;
//    //    {
//    //        std::lock_guard<std::mutex> lock(mtx);
//    //        stopThread = true;
//    //    }
//    //    cv.notify_all();
//    //    if (backgroundMusicThread.joinable())
//    //    {
//    //        backgroundMusicThread.join();
//    //    }
//    //}
//}

bool MusicManager::getBackMusicPlaying() const
{
    return m_backgroundMusicPlaying;
}

sf::Music& MusicManager::getMusicTrack(int track)
{
    return *m_backgroundMusic[track];
}

void MusicManager::stopBackgroundMusic()
{
    if (m_backgroundMusicPlaying || true)
    {
        m_backgroundMusic[m_currMusicIndex]->pause();
        m_backgroundMusic[m_currMusicIndex]->setPlayingOffset(sf::Time::Zero);
        m_backgroundMusicPlaying = false;
    }
}

void MusicManager::setCurrMusic(int track)
{
    m_currMusicIndex = track;
}
