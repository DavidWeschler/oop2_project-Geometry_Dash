#include "ButtonCommand/HowToPlayCommand.h"

HowToPlayCommand::HowToPlayCommand(int& index, int dir)
	: m_explanationIndex(index), m_dir(dir)
{}

void HowToPlayCommand::execute()
{
	m_explanationIndex += m_dir;
}