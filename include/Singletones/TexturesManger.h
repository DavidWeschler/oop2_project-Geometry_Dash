#pragma once

#pragma region headers

#include <SFML/Graphics.hpp>
#include <string.h>
#include <unordered_map>
#include "Singletones/GlobalConsts.h"
#include "Animations/AnimationData.h"
#include <vector>

#pragma endregion headers

enum enemies {
    Robot_E
};

enum class PlayerState {
    FORWARD_S,
    SPACESHIP_S,
    UPSIDEDOWN_S,
    UPSIDESPACESHIP_S
};

enum class GameStates {
    MENU_S,
    GAME_S,
    CHOOSE_PLAYER_S,
    NEXT_LEVEL_S,
    HOW_TO_PLAY_S,        
    STATISTICS_S
};

class TexturesManger
{
public:
    ~TexturesManger() = default;
    static TexturesManger& instance();

    sf::Texture& getButtonTextures(int num);
    sf::Texture& getSetButtonTexture(int num);
    sf::Texture& getBackButtonTexture(int num);
    sf::Texture& getMenuButtonTexture(int num);
    sf::Texture& getMenuBackground(int i);
    sf::Texture& getPrompt(int i);
    sf::Texture& getPlayerTexture(int num);
    sf::Texture& getObjTexture(int num);
    sf::Image getImage(int i) const;
    sf::Texture& getCursor();
    sf::Texture& getUrlButtonTexture(int i);
    sf::Texture& getHowToPlayTexture(int num);
    sf::Texture& getBulletTexture(int num);
    sf::Texture& getWellDoneTexture();
    sf::Texture& getStatsTexture();
    sf::Texture& getNoStatsTexture();

    const sf::Font& getFont() const;
    void LoadFromFile();
    const AnimationData& animationData(enemies object);

private:
    TexturesManger();
    TexturesManger(const TexturesManger&) = delete;
    TexturesManger operator=(const TexturesManger&) = delete;
    AnimationData robotData();

    std::vector<AnimationData> m_data;
    sf::Font m_font;  
    std::vector<sf::Texture> m_buttonTextures;
    std::vector<sf::Texture> m_setsTextures;
    std::vector<std::string> m_setsNames = {
        "ClassicYellowSet.png",
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
    std::vector<std::string> m_backButtNames = { 
        "ExitButton.png", 
        "ReturnButton.png", 
        "PauseButton.png"};
    std::vector<std::string> m_menuTools = { 
        "MenuBackground.png", 
        "menuText.png" , 
        "CustomizeText.png"};

    sf::Image m_icon;
    sf::Texture m_cursor;
    std::vector<sf::Texture> m_menusTextures;
    std::vector<sf::Texture> m_menuButtonTextures;
    std::vector<std::string> m_menuButtonsNames = { 
        "ShapeButton.png", 
        "StartButton.png", 
        "MusicButton.png", 
        "HighScoreButton.png", 
        "HelpButton.png",  
        "NextLeveBacklButton.png" ,
        "NextLevelButton.png" ,
        "NextSlideButton.png", 
        "PrevSlideButton.png"};
    std::vector<sf::Texture> m_playerTextures;
    std::vector<std::string> m_playerNames = { 
        "ClassicYellowPlayer.png", 
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
    std::vector<std::string> m_objNames = { 
        "Block.png", 
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
        "Robot.png",
        "Block_v.png",
        "GroundJumpUpside.png",
        "LongSpike.png",
        "LongSpikeUpside.png",
        "UpsideSpaceshipPortal.png"};

    std::vector<std::string> m_urlNames = { 
        "LinkedIn.png", 
        "git.png", 
        "yt.png"};
    std::vector<sf::Texture> m_urlTexture;
    std::vector<sf::Texture> m_promptTexture;
    std::vector<sf::Texture> m_howToPlay;
    std::vector<std::string> m_slides = {
        "Slide0.png", 
        "Slide1.png", 
        "Slide2.png", 
        "Slide3.png", 
        "Slide4.png", 
        "Slide5.png", 
        "Slide6.png", 
        "Slide7.png", 
        "Slide8.png", 
        "Slide9.png" };
    sf::Texture m_howToPlayBackground;
    std::vector<sf::Texture> m_bulletsTex;
    std::vector<std::string> m_bulletNames = { 
        "bullet0.png",
        "bullet1.png", 
        "bullet2.png", 
        "bullet3.png", 
        "bullet4.png", 
        "bullet5.png", 
        "bullet6.png", 
        "bullet7.png" };
    std::vector<std::string> m_levelNames = { 
        "RageOfTheElements.png", 
        "ToxicWastelands.png", 
        "BlazingBastion.png", 
        "ThunderstormTemple.png",
        "GeometryPirates.png"};
    std::vector<std::string> m_promptsNames = {
        "try again.png", 
        "Come on, be focused.png", 
        "you can do this.png", 
        "Fall. Learn. Rise. Repeat..png", 
        "You got this.png", 
        "Bounce back.png", 
        "Stay focused.png", 
        "Keep pushing.png"};
    std::vector<sf::Image> m_images;
    sf::Texture m_wellDone;
    sf::Texture m_statsBackground;
    sf::Texture m_noStatsBackground;;
};