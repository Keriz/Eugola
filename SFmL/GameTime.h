/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-GameTime.h-
Classe de gestion du temps, accesible partout.
*/

#ifndef GAMETIME
#define GAMETIME

#pragma region Include
#include <SFML\System\Clock.hpp>
#pragma endregion

class GameTime : public sf::Clock {
		sf::Time m_ElapsedTime;
		sf::Clock *m_Clock;
public:
	GameTime::GameTime();
	GameTime::~GameTime();
	sf::Time getElapsedTime();
};

#endif