#include "NextStateCommand.h"
#include "Controller.h"
#include "GameState.h"


NextStateCommand::NextStateCommand(Controller& controller, GameState& nextState)
	: m_controller(controller), m_nextState(nextState)
{
}

void NextStateCommand::execute()
{
	puts("excecuting");
	m_controller.switchState(&m_nextState);
}