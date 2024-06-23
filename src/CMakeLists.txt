file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} 

"../include/Menu.h" "Menu.cpp" 
"../include/Singleton.h" 
"Singleton.cpp" "../include/Button.h" "Button.cpp" "../include/Game.h" "Game.cpp" 
"../include/ChoosePlayer.h" "ChoosePlayer.cpp" "../include/GameState.h" "../include/Controller.h" 
"Controller.cpp" "Object.cpp" "../include/GameObj/StaticObj/Block.h" "Block.cpp" "../include/GameObj/StaticObj/Spike.h" "Spike.cpp" 
"../include/GameObj/MovablesObj/Player.h" "Player.cpp" "../include/GameObj/MovablesObj/Robot.h" "../include/Enemy.h" "Robot.cpp" "../include/Weapon.h"
"Weapon.cpp" "../include/GameObj/StaticObj/Portals/Portal.h" "Portal.cpp" "../include/Crusher.h" "Crusher.cpp" "../include/GameInfo.h" "GameInfo.cpp" 
"../include/GameObj/StaticObj/Static.h" "Static.cpp" "../include/GameObj/MovablesObj/Movable.h" "Movable.cpp" "../include/PauseState.h" "PauseState.cpp" "../include/HighScoreState.h" 
"HighScoreState.cpp" "../include/HowToPlayState.h" "HowToPlayState.cpp" "../include/WinGameState.h" "ContactListener.cpp" "../include/MusicManager.h" 
"MusicManager.cpp" "../include/GameObj/StaticObj/Portals/SpaceShipPortal.h" "../include/GameObj/StaticObj/Portals/GravityPortal.h" "../include/GameObj/StaticObj/Portals/ForwardPortal.h" "../include/FactoryFixed.h" 
"FactoryFixed.cpp" "GravityPortal.cpp" "SpaceShipPortal.cpp" "ForwardPortal.cpp" "Arrow.cpp" "../include/MoveState.h" "MoveState.cpp" 
"../include/ForwardState.h" "ForwardState.cpp" "../include/FlyState.h" "FlyState.cpp" "../include/UpsideDownState.h" "AirJump.cpp" "GroundJump.cpp" "FinishPortal.cpp" "../include/GameObj/StaticObj/Portals/FinishPortal.h" "../include/Animation.h" "../include/AnimationData.h" "Animation.cpp" "../include/Direction.h" "../include/ButtonCommand.h" "../include/NextStateCommand.h" "../include/ExitCommand.h" "../include/ChoosePlayerCommand.h" "../include/MusicCommand.h" "MusicCommand.cpp" "NextStateCommand.cpp" "ExitCommand.cpp" "../include/LinkedInCommand.h" "../include/NextLevelWindow.h" "NextLevelWindow.cpp")
