#pragma once
#pragma region headers
#include "ButtonCommand/ButtonCommand.h"
#include "Singletones/TexturesManger.h"
#pragma endregion headers

class Controller;
class GameState;

class NextStateCommand : public ButtonCommand
{
public:
	NextStateCommand(Controller& controller, GameStates nextState);	
	virtual ~NextStateCommand() = default;
	virtual void execute();

private:
	Controller& m_controller;
	GameStates m_nextState;
};