#pragma once
#include <SFML/Graphics.hpp>

const int WINDOW_X = sf::VideoMode::getDesktopMode().width / 1.2;
const int WINDOW_Y = sf::VideoMode::getDesktopMode().height / 1.2;

const int RGB_UPPER_LIMIT = 240;
const int RGB_LOWER_LIMIT = 100;

const int NUM_OF_BUTTONS = 6;
const int NUM_OF_MENU_BUTTONS = 9;
const int URL_BUTTON_NAME = 3;
const int NUM_OF_CHOOSE_SETS = 15;
const int NUM_OF_LEVELS = 2;
const int NUM_OF_PLAYERS = 30;
const int NUM_OF_OBJ = 18;
const int NUM_OF_HOW_TO_PLAY = 9;
const int NUM_OF_BULLETS = 8;

//----------Box2D----------------
const float GRAVITY_X = 0.0f;
const float GRAVITY_Y = 100.0f;
const float TIME_STEP = 1.0 / 60.0f;
const float VELOCITY = 22.0f;
const float ENEMY_VELOCITY = 13.0f;
const float BULLET_VELOCITY = 35.0f;

//--------Animation--------------
const auto AnimationTime = sf::seconds(0.05f);

const sf::Color BLOCK_C = sf::Color::Black;
const sf::Color ARROW_C = sf::Color(105, 230, 232);
const sf::Color BLOCK_M_C = sf::Color(163, 73, 164);
const sf::Color BLOCK_V_C = sf::Color(29,07,98);
const sf::Color GRAVITY_PORTAL_C = sf::Color(70, 170, 70);
const sf::Color SPACESHIP_PORTAL_C = sf::Color::Blue;
const sf::Color FORWARD_PORTAL_C = sf::Color(170, 170, 70);
const sf::Color UPSIDESPACESHIP_PORTAL_C = sf::Color(190, 190, 90);
const sf::Color FINISH_PORTAL_C = sf::Color(128, 128, 128);
const sf::Color PLAYER_C = sf::Color::Red;
const sf::Color SPIKE_C = sf::Color::Green;
const sf::Color DOWN_SPIKE_C = sf::Color(0, 250, 0);
const sf::Color LONG_SPIKE_C = sf::Color(136, 0, 0);
const sf::Color DOWN_LONG_SPIKE_C = sf::Color(190, 0, 0);
const sf::Color AIR_SPIKE_C = sf::Color(143, 250, 29);
const sf::Color ROBOT_C = sf::Color(100, 50, 100);
const sf::Color AIR_JUMP_C = sf::Color(255, 128, 192);
const sf::Color GROUND_JUMP_C = sf::Color(255, 128, 64);
const sf::Color GROUND_JUMP_U_C = sf::Color(64, 128, 64);
const sf::Color BULLET_C = sf::Color(204, 204, 0);