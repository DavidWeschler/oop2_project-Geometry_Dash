#pragma once
#include "ButtonCommand.h"
#include "windows.h"
#include <string>

class LinkedInCommand : public ButtonCommand
{
public:
	LinkedInCommand(const std::string& url) : m_url(url) {}
	virtual ~LinkedInCommand() = default;
	virtual void execute()
	{
		ShellExecute(0, 0, m_url.c_str(), 0, 0, SW_SHOW);
	}
private:
	std::string m_url;
};
