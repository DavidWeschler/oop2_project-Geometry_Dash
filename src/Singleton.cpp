#include "Singleton.h"
#include <iostream>

Singleton::Singleton()
{
	LoadFromFile();
}


sf::Texture& Singleton::getMenuBackground(int i)
{
	return m_menusTextures[i];
}

sf::Texture& Singleton::getPlayerTexture(int num)
{
	return m_playerTextures[num];
}

sf::Texture& Singleton::getObjTexture(int num)
{
	return m_objTextures[num];
}

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
	for (int i = 0; i < 3; i++)
	{
		m_menusTextures.push_back(sf::Texture());
		if (!(m_menusTextures[i].loadFromFile(m_menunTools[i])))
		{
			exit(EXIT_FAILURE);
		}
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

	//Load Player Faces and ships
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		m_playerTextures.push_back(sf::Texture());
		if (!(m_playerTextures[i].loadFromFile(m_playerNames[i])))
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


	//Load objects
	for (int i = 0; i < NUM_OF_OBJ; i++)
	{
		m_objTextures.push_back(sf::Texture());
		if (!(m_objTextures[i].loadFromFile(m_objNames[i])))
		{
			exit(EXIT_FAILURE);
		}
	}

	m_data.push_back(robotData());
}

AnimationData Singleton::robotData()
{
	const auto size = sf::Vector2i(3601/11, 330);
	const auto initSpace = sf::Vector2i(0, 0);
	const auto middleSpace = sf::Vector2i(0, 0);

	AnimationData robot;
	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			//currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};

	robot.m_data[Direction::Right].emplace_back(currentStart, size);
	robot.m_data[Direction::Right].emplace_back(nextStart(), size);
	robot.m_data[Direction::Left].emplace_back(nextStart(), size);
	robot.m_data[Direction::Left].emplace_back(nextStart(), size);

	return robot;
}