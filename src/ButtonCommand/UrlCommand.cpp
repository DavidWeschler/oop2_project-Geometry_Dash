#include "ButtonCommand/UrlCommand.h"

void UrlCommand::execute()
{
	ShellExecute(0, 0, m_url.c_str(), 0, 0, SW_SHOW);
}