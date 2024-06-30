#pragma region headers
#include "ButtonCommand/NextStateCommand.h"
#include "ScreenStates/Controller.h"
#include "ScreenStates/GameState.h"
#pragma endregion headers

NextStateCommand::NextStateCommand(Controller& controller, GameStates nextState)
	:m_controller(controller), m_nextState(nextState)
{}

void NextStateCommand::execute()
{
	m_controller.switchState(m_nextState);
}