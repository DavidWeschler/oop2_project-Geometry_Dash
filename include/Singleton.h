#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <unordered_map>
#include "GlobalConsts.h"

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
    BLUE_ROBOT_SET, 
    CYAN_SET, 
    ALIEN_SET, 
    ORANGE_BOX_SET, 
    PURPLE_WHEEL_SET, 
    ANGRY_SET
};

enum class ObjectTypes {
    BLOCK_T,
    BLOCK_M_T,
    SPIKE_T,
    GRAVITY_PORTAL_T,
    SPACESHIP_PORTAL_T,
    FORWARD_PORTAL_T,
    FINISH_PORTAL_T,
    ROBOT_T,
    AIR_JUMP_T,
    CRUSHER_T,
    GROUND_JUMP_T,
    WEAPON_T,
    ARROW_T,
    MOVABLE_T,
    FIXED_T,
    ERROR_T
};

enum class PlayerState {
    FORWARD_S,
    SPACESHIP_S,
    UPSIDEDOWN_S
};


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
    enum Buttons m_setNames[NUM_OF_CHOOSE_SETS] = { CLASSIC_SET,  DEMON_SET, GREENIE_SET, PINK_SET, SHARK_SET, MONSTER_SET, WHITE_SET, CROWN_SET, ROBOT_SET, BLUE_ROBOT_SET, CYAN_SET, ALIEN_SET, ORANGE_BOX_SET, PURPLE_WHEEL_SET, ANGRY_SET};

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
                                            "BlueRobotSet.png",
                                            "CyanWheelSet.png", 
                                            "OrangeAlienSet.png", 
                                            "OrangeBoxSet.png", 
                                            "PurpleWheelSet.png", 
                                            "RedAngrySet.png"};

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
                                                "BlueRobotPlayer.png",
                                                "CyanWheelPlayer.png",
                                                "OrangeAlienPlayer.png",
                                                "OrangeBoxPlayer.png",
                                                "PurpleWheelPlayer.png",
                                                "RedAngryPlayer.png",

                                                "ClassicYellowShip.png",
                                                "EvilDemonShip.png",
                                                "GreenieShip.png",
                                                "PinkSmileShip.png",
                                                "PurpleSharkShip.png",
                                                "RedMonsterShip.png",
                                                "WhiteCloudShip.png",
                                                "YellowCrownShip.png",
                                                "RedRobotShip.png",
                                                "BlueRobotShip.png",
                                                "CyanWheelShip.png",
                                                "OrangeAlienShip.png",
                                                "OrangeBoxShip.png",
                                                "PurpleWheelShip.png",
                                                "RedAngryShip.png" };

    std::vector<sf::Texture> m_objTextures;
    std::vector<std::string> m_objNames = { "Block.png", 
                                            "Block_m.png", 
                                            "Spike.png" , 
                                            "GravityPortal.png", 
                                            "SpaceShipPortal.png", 
                                            "DirectionPortal.png", 
                                            "Arrow.png", 
                                            "DownSpike.png", 
                                            "AirSpike.png",
                                            "AirJump.png",
                                            "GroundJump.png",
                                            "FinishPortal.png",
                                            "Robot.png"};

    std::vector<std::string> m_levelNames = { "Level01.png" };
    std::vector<sf::Image> m_images;
};