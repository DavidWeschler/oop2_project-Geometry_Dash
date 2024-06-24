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
    void setBackgroundMusic();
    //void stopBackgroundMusic();

    bool getBackMusicPlaying() const;
    sf::Music& getMusicTrack(int track);

    void stopBackgroundMusic();
    void setCurrMusic(int track);

    void setMuteAll(bool state);
    bool getMuteAllState() const;

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
    bool m_muteAll = false;

    //std::thread backgroundMusicThread;
    //std::condition_variable cv;
    //std::mutex mtx;
    //bool stopThread = false;

    //---------background music-------------
    //std::vector<sf::Music> m_backgroundMusic;
    std::vector<std::unique_ptr<sf::Music>> m_backgroundMusic;
    //std::vector<sf::SoundBuffer> m_musicBuffSounds;
    std::vector<std::string> m_musicNames = { "intro.ogg" ,"practice.ogg", "ForeverBound - Stereo Madness.ogg", "DJVI - Back On Track.ogg", "Step - Polargeist.ogg", "DJVI - Dry Out.ogg", "DJVI - Base After Base.ogg", "DJVI - Can't Let Go.ogg", "Waterflame - Time Machine.ogg", "DJVI - Cycles.ogg"};
};
