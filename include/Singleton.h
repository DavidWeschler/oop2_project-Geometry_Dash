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

//enum class ObjectTypes {
//    BLOCK_T,
//    SPIKE_T,
//    GRAVITY_PORTAL_T,
//    SPACESHIP_PORTAL_T,
//    DIRECTION_PORTAL_T,
//    ROBOT_T,
//    AIR_JUMP_T,
//    CRUSHER_T,
//    GROUND_JUMP_T,
//    WEAPON_T
//};

//-------------const----------------
const int WINDOW_X = sf::VideoMode::getDesktopMode().width / 1.2;
const int WINDOW_Y = sf::VideoMode::getDesktopMode().height / 1.2;

const int NUM_OF_BUTTONS = 6;
const int NUM_OF_MENU_BUTTONS = 6;
const int NUM_OF_CHOOSE_SETS = 10;
const int NUM_OF_LEVELS = 1;
const int NUM_OF_PLAYERS = 10;
const int NUM_OF_OBJ = 7;

//----------Box2D----------------
const float GRAVITY_X = 0.0f;
const float GRAVITY_Y = 6.0f;
const float TIME_STEP = 1.0/60.0f;
const float VELOCITY = 20.f;

const sf::Color BLOCK_C = sf::Color::Black;
const sf::Color GRAVITY_PORTAL_C = sf::Color(70,170,70);
const sf::Color SPACESHIP_PORTAL_C = sf::Color::Blue;
const sf::Color DIRECTION_PORTAL_C = sf::Color(170,170,70);
const sf::Color PLAYER_C = sf::Color::Red;
const sf::Color SPIKE_C = sf::Color::Green;
const sf::Color ROBOT_C = sf::Color(100,50,100);
const sf::Color ARROW_C = sf::Color(105,230,232);
const sf::Color BLOCK_M_C = sf::Color(163,73,164);


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
    sf::Texture& getMenuBackground(int i);
    sf::Texture& getPlayerTexture(int num);
    sf::Texture& getObjTexture(int num);
    sf::Image getImage(int i) const;

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
    std::vector<std::string> m_menunTools = { "MenuBackground.png", "menuText.png" , "CustomizeText.png"};

    sf::Image m_icon;
    std::vector<sf::Texture> m_menusTextures;
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
    std::vector<std::string> m_objNames = { "Block.png", "Block_m.png", "Spike.png" , "GravityPortal.png", "SpaceShipPortal.png", "DirectionPortal.png", "Arrow.png"};

    std::vector<std::string> m_levelNames = { "Level01.png" };
    std::vector<sf::Image> m_images;
};