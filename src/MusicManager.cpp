#include "MusicManager.h"

MusicManager::MusicManager()
{
	loadMusic();
}

MusicManager& MusicManager::instance()
{
	static MusicManager musicManager;
	return musicManager;
}

//void MusicManager::loadMusic()
//{
//	//load music
//
//	for (int i = 0; i < m_musicNames.size(); i++)
//	{
//		m_backgroundMusic.push_back(sf::Music());
//		if (!(m_backgroundMusic[i].openFromFile(m_musicNames[i])))
//		{
//			//std::cerr << "cannot load music\n";
//			exit(EXIT_FAILURE);
//		}
//	}
//}