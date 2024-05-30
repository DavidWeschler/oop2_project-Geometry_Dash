#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>


//------------enum-------------
enum Buttons {
    SHAPE,
    START,
    MUSIC,
    HIGH_SCORE,
    HOW_TO_PLAY,
    EXIT,
    RETURN,
    DEFAULT,
    CLASSIC_SET,
    DEMON_SET,
    GREENIE_SET,
    PINK_SET,
    SHARK_SET,
    MONSTER_SET,
    ROBOT_SET,
    WHITE_SET,
    CROWN_SET
};

//-------------const----------------
const int WINDOW_X = sf::VideoMode::getDesktopMode().width / 1.2;
const int WINDOW_Y = sf::VideoMode::getDesktopMode().height / 1.2;

const int NUM_OF_BUTTONS = 6;
const int NUM_OF_MENU_BUTTONS = 6;
const int NUM_OF_CHOOSE_SETS = 9;
//const int NUM_OF_GAME_BUTTONS = 3;
//const int STICK_PARAMETERS = 6;
//
//const sf::Color BLACK(64, 64, 65);
//const sf::Color ORANGE(255, 145, 0);
//const sf::Color GREEN(65, 186, 12);

class Singleton
{
public:
    ~Singleton() = default;
    static Singleton& instance();
    enum Buttons getButtonName(int i) const;
    enum Buttons getSetsNames(int i) const;

    sf::Texture& getButtonTextures(int num);
    sf::Texture& getSetButtonTexture(int num);
    //sf::Texture& getGameBackground();
    //sf::Texture& getMenuBackground();
    //sf::Texture& getFileNotFound();
    //sf::Texture& getLoseScreen();
    //sf::Texture& getWinScreen();
    //const sf::Font& getFont() const;

    void LoadFromFile();

private:
    Singleton();
    Singleton(const Singleton&) = delete;

    Singleton operator=(const Singleton&) = delete;

  enum Buttons m_names[NUM_OF_BUTTONS] = { SHAPE, START, MUSIC, HIGH_SCORE, HOW_TO_PLAY, EXIT};
  enum Buttons m_setNames[NUM_OF_CHOOSE_SETS] = { CLASSIC_SET,  DEMON_SET, GREENIE_SET, PINK_SET, SHARK_SET, MONSTER_SET, WHITE_SET, CROWN_SET, ROBOT_SET};
  enum Buttons m_exitName = RETURN;


  // sf::Font m_font;
  //  sf::Texture m_gameBackground;
  //  sf::Texture m_menuBackground;
  //  sf::Texture m_fileNotFound;
  //  sf::Texture m_fileFault;
  //  sf::Texture m_winScreen;
  //  sf::Texture m_loseScreen;
    std::vector<sf::Texture> m_buttonTextures;
    std::vector<sf::Texture> m_setsTextures;
    std::vector<std::string> m_setsNames = {"ClassicYellowSet.png",
                                            "EvilDemonSet.png",
                                            "GreenieSet.png",
                                            "PinkSmileSet.png",
                                            "PurpleSharkSet.png",
                                            "RedMonsterSet.png",
                                            "WhiteCloudSet.png",
                                            "YellowCrownSet.png",
                                            "RedRobotSet.png" };

    //std::vector<std::string> m_nameOfBackgrounds = { "MenuBack.png",
    //                                                "GameBack.png" };
    //std::vector<std::string> m_endScreens = { "WinScreen.png",
    //                                         "LoseScreen.png" };
    //std::string m_nameOfExemption = "FileNotFound.png";
    //std::vector<std::string> m_buttonNames = { "Start.png",
    //                                          "Load.png",
    //                                          "Exit.png",
    //                                          "Hint.png",
    //                                          "Save.png",
    //                                          "Menu.png" };
};