#pragma once

#include <SFML/Audio.hpp>
#include <memory>
#include <string>
#include <vector>

class MusicManager 
{
public:
    // Get the instance of the singleton
    static MusicManager& instance();

    // Load music from a file
    void loadMusic();
    void playBackgroundMusic();
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
    int m_currMusicIndex;
    bool m_backgroundMusicPlaying;

private:
    MusicManager();
    MusicManager(const MusicManager&) = delete;
    MusicManager& operator=(const MusicManager&) = delete;


    //---------background music-------------
    //std::vector<sf::Music> m_backgroundMusic;
    std::vector<std::unique_ptr<sf::Music>> m_backgroundMusic;
    //std::vector<sf::SoundBuffer> m_musicBuffSounds;
    std::vector<std::string> m_musicNames = { "MenuMusic.ogg"};
};
