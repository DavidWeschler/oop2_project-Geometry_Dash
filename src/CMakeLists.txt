file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} 

"../include/Menu.h" "Menu.cpp" 
"../include/Singleton.h" 
"Singleton.cpp" "../include/Button.h" "Button.cpp" "../include/Game.h" "Game.cpp" 
"../include/ChoosePlayer.h" "ChoosePlayer.cpp" "../include/GameState.h" "../include/Controller.h" 
"Controller.cpp" "Object.cpp" "../include/Block.h" "Block.cpp" "../include/Spike.h" "Spike.cpp" 
"../include/Player.h" "Player.cpp" "../include/Robot.h" "../include/Enemy.h" "Robot.cpp" "../include/Weapon.h"
"Weapon.cpp" "../include/Portal.h" "Portal.cpp" "../include/Crusher.h" "Crusher.cpp" "../include/GameInfo.h" "GameInfo.cpp" 
"../include/Static.h" "Static.cpp" "../include/Movable.h" "Movable.cpp" "../include/PauseState.h" "PauseState.cpp" "../include/HighScoreState.h" 
"HighScoreState.cpp" "../include/HowToPlayState.h" "HowToPlayState.cpp" "../include/WinGameState.h" "ContactListener.cpp" "../include/MusicManager.h" 
"MusicManager.cpp" "../include/SpaceShipPortal.h" "../include/GravityPortal.h" "../include/ForwardPortal.h" "../include/FactoryFixed.h" 
"FactoryFixed.cpp" "GravityPortal.cpp" "SpaceShipPortal.cpp" "ForwardPortal.cpp" "Arrow.cpp" "../include/MoveState.h" "MoveState.cpp" 
"../include/ForwardState.h" "ForwardState.cpp" "../include/FlyState.h" "FlyState.cpp" "../include/UpsideDownState.h")
