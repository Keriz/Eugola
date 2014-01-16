#include "GameTime.h"

GameTime::GameTime()
{
	m_Clock = new sf::Clock();
	m_ElapsedTime = m_Clock->getElapsedTime();
}

GameTime::~GameTime()
{
	delete m_Clock;
}

sf::Time GameTime::getElapsedTime()
{
	m_ElapsedTime = m_Clock->getElapsedTime();
		return m_ElapsedTime;
}