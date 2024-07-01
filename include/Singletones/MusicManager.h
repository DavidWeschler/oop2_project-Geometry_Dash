#pragma once
#pragma region headers
#include <SFML/Audio.hpp>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <condition_variable>
#pragma endregion headers

class MusicManager 
{
public:
    static MusicManager& instance();
    void loadMusic();

    sf::Music& getMusicTrack(int track);
    sf::Music& getShootSound();

    void stopBackgroundMusic();
    void setCurrMusic(int track);

    void setMuteAll(bool state);
    bool getMuteAllState() const;

private:
    MusicManager();
    MusicManager(const MusicManager&) = delete;
    MusicManager& operator=(const MusicManager&) = delete;

    int m_currMusicIndex;
    bool m_muteAll = false;

    std::vector<std::unique_ptr<sf::Music>> m_backgroundMusic;
    std::unique_ptr<sf::Music> m_shootSound;
    std::vector<std::string> m_musicNames = { "intro.ogg", "ForeverBound - Stereo Madness.ogg", "DJVI - Back On Track.ogg", "Step - Polargeist.ogg", "DJVI - Dry Out.ogg", "DJVI - Base After Base.ogg", "DJVI - Can't Let Go.ogg", "Waterflame - Time Machine.ogg", "DJVI - Cycles.ogg"};
};
