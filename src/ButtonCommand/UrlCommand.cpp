#include "ButtonCommand/UrlCommand.h"

void UrlCommand::execute()
{
	ShellExecute(0, // or NULL: no parent window
		0,		   // action to be performed
		m_url.c_str(), // file on which to execute the specified operation
		0, // of NULL: parameters to be passed to the application
		0,	// working directory (current us closed)
		SW_SHOW);	// how the application window should be displayed (recent size and position)
}