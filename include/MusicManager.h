#pragma once

#include <SFML/Audio.hpp>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <condition_variable>

class MusicManager 
{
public:
    // Get the instance of the singleton
    static MusicManager& instance();

    // Load music from a file
    void loadMusic();
    void playBackgroundMusic();
    void stopBackgroundMusic();
    //sf::Music& getMusic();
    //// Control music playback
    //void play();
    //void pause();
    //void stop();

    //// Set volume
    //void setVolume(float volume);

    //// Check if music is playing
    //bool isPlaying() const;
      // Index of the currently playing background music

private:
    MusicManager();
    MusicManager(const MusicManager&) = delete;
    MusicManager& operator=(const MusicManager&) = delete;

    int m_currMusicIndex;
    bool m_backgroundMusicPlaying;
    std::thread backgroundMusicThread;
    std::condition_variable cv;
    std::mutex mtx;
    bool stopThread = false;

    //---------background music-------------
    //std::vector<sf::Music> m_backgroundMusic;
    std::vector<std::unique_ptr<sf::Music>> m_backgroundMusic;
    //std::vector<sf::SoundBuffer> m_musicBuffSounds;
    std::vector<std::string> m_musicNames = { "MenuMusic.ogg"};
};
