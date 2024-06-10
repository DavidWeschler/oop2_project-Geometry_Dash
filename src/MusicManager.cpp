#include "MusicManager.h"
#include <thread>


MusicManager::MusicManager()
{
    m_currMusicIndex = 0;
	loadMusic();
    playBackgroundMusic();
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

void MusicManager::playBackgroundMusic()
{
    puts("here");

    if (!m_backgroundMusicPlaying)
    {
        m_backgroundMusicPlaying = true;

        // Thread to continuously play background music
        std::thread backgroundMusicThread([this]() {
            sf::Music& music = *m_backgroundMusic[0]; // Assuming you want to play the first music in the vector
            while (m_backgroundMusicPlaying)
            {
                if (music.getStatus() != sf::Music::Playing)
                {
                    music.play();
                    music.setVolume(0.3f);
                }
                // Adjust sleep time based on your requirements
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            });

        backgroundMusicThread.detach(); // Detach the thread to run independently
    }
}
