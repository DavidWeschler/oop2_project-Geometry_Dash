file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} 

"../include/Animations/Animation.h" 
"../include/Animations/AnimationData.h" 
"../include/Animations/Direction.h"

"../include/ButtonCommand/ButtonCommand.h" 
"../include/ButtonCommand/Button.h"
"../include/ButtonCommand/NextStateCommand.h"
"../include/ButtonCommand/ExitCommand.h"
"../include/ButtonCommand/ChoosePlayerCommand.h" 
"../include/ButtonCommand/MusicCommand.h"
  "../include/ButtonCommand/LinkedInCommand.h" 

 "../include/GameObj/MovablesObj/Movable.h"
"../include/GameObj/MovablesObj/Enemy.h"
"../include/GameObj/MovablesObj/Robot.h"
  "../include/GameObj/MovablesObj/Player.h"  

"../include/GameObj/StaticObj/Block.h" 
"../include/GameObj/StaticObj/Spike.h" 
 "../include/GameObj/StaticObj/Static.h"

 "../include/GameObj/StaticObj/Portals/Portal.h"
  "../include/GameObj/StaticObj/Portals/SpaceShipPortal.h"
 "../include/GameObj/StaticObj/Portals/GravityPortal.h"
"../include/GameObj/StaticObj/Portals/ForwardPortal.h"
"../include/GameObj/StaticObj/Portals/FinishPortal.h"

  "../include/MovingStates/MoveState.h" 
  "../include/MovingStates/ForwardState.h" 
  "../include/MovingStates/FlyState.h" 
  "../include/MovingStates/UpsideDownState.h" 

  "../include/ScreenStates/NextLevelWindow.h" 


"../include/ScreenStates/Menu.h" 
"../include/ScreenStates/Game.h" 
"../include/ScreenStates/ChoosePlayer.h" 
"../include/ScreenStates/GameState.h" 
"../include/ScreenStates/Controller.h" 
 "../include/ScreenStates/PauseState.h"
 "../include/ScreenStates/HighScoreState.h"
 "../include/ScreenStates/HowToPlayState.h"
 "../include/ScreenStates/WinGameState.h" 

"../include/Singletones/TexturesManger.h"
 "../include/Singletones/MusicManager.h"
"../include/Singletones/FactoryFixed.h"
 "../include/ButtonCommand/HowToPlayCommand.h" "ButtonCommand/HowToPlayCommand.cpp" "../include/GameObj/MovablesObj/Bullet.h" "GameObj/MovablesObj/Bullet.cpp")
