#include "ChoosePlayerCommand.h"

#include "Menu.h"
#include "Controller.h"

ChoosePlayerCommand::ChoosePlayerCommand(Menu& menu, Controller& controller, int buttonChoice)
	: m_menu(menu), m_controller(controller), m_chosenSprite(buttonChoice)
{
}

void ChoosePlayerCommand::execute()
{
	m_menu.setChosenPlayer(m_chosenSprite);
	m_controller.switchState((GameState*)(&m_menu));	//good?
}
