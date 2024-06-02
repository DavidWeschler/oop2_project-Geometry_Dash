#include "Singleton.h"
#include <iostream>

Singleton::Singleton()
{
	LoadFromFile();
}

sf::Texture& Singleton::getMenuBackground()
{
	return m_menusTexture;
}

// Singleton::getGameColor(MapObjColors color)
//{
//	return m_colorMap.at(color);
//}

 sf::Image Singleton::getImage(int i) const
 {
	 return m_images[i];
 }

Singleton& Singleton::instance()
{
	static Singleton Singleton;
	return Singleton;
}

sf::Texture& Singleton::getButtonTextures(int num)
{
	return m_buttonTextures[num];
}

sf::Texture& Singleton::getSetButtonTexture(int num)
{
	return m_setsTextures[num];
}

sf::Texture& Singleton::getBackButtonTexture(int num)
{
	return m_backButtonTextures[num];
}

sf::Texture& Singleton::getMenuButtonTexture(int num)
{
	return m_menuButtonTextures[num];
}

Buttons Singleton::getButtonName(int i) const
{
	return m_names[i];
}

Buttons Singleton::getSetsNames(int i) const
{
	return m_setNames[i];
}

void Singleton::LoadFromFile()
{
	//Load exit & return Buttons
	if (!(m_menusTexture.loadFromFile(m_menunName)))
	{
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 3; i++)
	{
		m_backButtonTextures.push_back(sf::Texture());
		if (!(m_backButtonTextures[i].loadFromFile(m_backButtNames[i])))
		{
			exit(EXIT_FAILURE);
		}
	}

	//Load Menu buttons
	for (int i = 0; i < 5; i++)
	{
		m_menuButtonTextures.push_back(sf::Texture());
		if (!(m_menuButtonTextures[i].loadFromFile(m_menuButtonsNames[i])))
		{
			std::cerr << "cannot load textures\n";
			exit(EXIT_FAILURE);
		}
	}

	//Load sets
	for (int i = 0; i < NUM_OF_CHOOSE_SETS; i++)
	{
		m_setsTextures.push_back(sf::Texture());
		if (!(m_setsTextures[i].loadFromFile(m_setsNames[i])))
		{
			std::cerr << "cannot load textures\n";
			exit(EXIT_FAILURE);
		}
	}


	//load images
	for (int i = 0; i < NUM_OF_LEVELS; i++)
	{
		m_images.push_back(sf::Image());
		if (!(m_images[i].loadFromFile(m_levelNames[i])))
		{
			exit(EXIT_FAILURE);
		}
	}
}
//
//const sf::Font& Singleton::getFont() const
//{
//	return m_font;
//}