#pragma once
#include "ButtonCommand/ButtonCommand.h"
#include "windows.h"
#include <string>

class UrlCommand : public ButtonCommand
{
public:
	UrlCommand(const std::string& url) : m_url(url) {}
	virtual ~UrlCommand() = default;
	virtual void execute();
private:
	std::string m_url;
};
