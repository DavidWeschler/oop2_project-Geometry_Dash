#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <unordered_map>

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
    CROWN_SET,
    RON_SET
};


//maybe erase
enum MapObjColors {
    BLACK,
    RED,
    WHITE,
    GREEN,
    BLUE,
    YELLOW
};

//-------------const----------------
const int WINDOW_X = sf::VideoMode::getDesktopMode().width / 1.2;
const int WINDOW_Y = sf::VideoMode::getDesktopMode().height / 1.2;

const int NUM_OF_BUTTONS = 6;
const int NUM_OF_MENU_BUTTONS = 6;
const int NUM_OF_CHOOSE_SETS = 10;
const int NUM_OF_LEVELS = 1;
const int NUM_OF_PLAYERS = 10;
const int NUM_OF_OBJ = 5;

//----------Box2D----------------
const float GRAVITY_X = 0.0f;
const float GRAVITY_Y = 18.81f;
const float TIME_STEP = 1.0/60.0f;


class Singleton
{
public:
    ~Singleton() = default;
    static Singleton& instance();
    enum Buttons getButtonName(int i) const;
    enum Buttons getSetsNames(int i) const;

    sf::Texture& getButtonTextures(int num);
    sf::Texture& getSetButtonTexture(int num);
    sf::Texture& getBackButtonTexture(int num);
    sf::Texture& getMenuButtonTexture(int num);
    sf::Texture& getMenuBackground();
    sf::Texture& getPlayerTexture(int num);
    sf::Texture& getObjTexture(int num);
    //sf::Color getGameColor(MapObjColors color);
    sf::Image getImage(int i) const;


    //const sf::Font& getFont() const;

    void LoadFromFile();

private:
    Singleton();
    Singleton(const Singleton&) = delete;

    Singleton operator=(const Singleton&) = delete;

    enum Buttons m_names[NUM_OF_BUTTONS] = { SHAPE, START, MUSIC, HIGH_SCORE, HOW_TO_PLAY, EXIT};
    enum Buttons m_setNames[NUM_OF_CHOOSE_SETS] = { CLASSIC_SET,  DEMON_SET, GREENIE_SET, PINK_SET, SHARK_SET, MONSTER_SET, WHITE_SET, CROWN_SET, ROBOT_SET, RON_SET};
    enum Buttons m_exitName = RETURN;


  // sf::Font m_font;
  
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
                                            "RedRobotSet.png",
                                            "CrazyRonSet.png"};

    std::vector<sf::Texture> m_backButtonTextures;
    std::vector<std::string> m_backButtNames = { "ExitButton.png", "ReturnButton.png", "PauseButton.png"};
    std::string m_menunName = "MenuBackground.png";

    sf::Texture m_menusTexture;
    std::vector<sf::Texture> m_menuButtonTextures;
    std::vector<std::string> m_menuButtonsNames = { "ShapeButton.png", "StartButton.png", "MusicButton.png", "HighScoreButton.png", "HelpButton.png"};

        
    std::vector<sf::Texture> m_playerTextures;
    std::vector<std::string> m_playerNames = { "ClassicYellowPlayer.png", 
                                                "EvilDemonPlayer.png", 
                                                "GreeniePlayer.png", 
                                                "PinkSmilePlayer.png", 
                                                "PurpleSharkPlayer.png", 
                                                "RedMonsterPlayer.png", 
                                                "WhiteCloudPlayer.png", 
                                                "YellowCrownPlayer.png",
                                                "RedRobotPlayer.png", 
                                                "CrazyRonPlayer.png" };

    std::vector<sf::Texture> m_objTextures;
    std::vector<std::string> m_objNames = { "Block.png", "Spike.png" , "GravityPortal.png", "SpaceShipPortal.png", "DirectionPortal.png"};


    // maybe erase
    std::unordered_map<MapObjColors, sf::Color> m_colorMap = { {BLACK, sf::Color::Black},
                                                            {RED, sf::Color::Red},
                                                            {WHITE, sf::Color::White},
                                                            {GREEN, sf::Color::Green},
                                                            {BLUE, sf::Color::Blue},
                                                            {YELLOW, sf::Color::Yellow} };  
                                        



    std::vector<std::string> m_levelNames = { "Level01.png" };
    std::vector<sf::Image> m_images;
};