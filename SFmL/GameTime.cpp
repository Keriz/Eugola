#include "GameTime.h"

GameTime::GameTime()
{
	//m_Clock = new sf::Clock();
	m_DesiredTime = 1.0f / 80.0f;
}

GameTime::~GameTime()
{
	//delete m_Clock;
}

sf::Time GameTime::restart()
{
	return Clock::restart();
}

sf::Time GameTime::getElapsedTime() const
{
	return Clock::getElapsedTime();
}

double GameTime::getDesiredTime() const
{
	return m_DesiredTime;
}