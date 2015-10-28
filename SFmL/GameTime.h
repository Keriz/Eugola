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
		//sf::Clock *m_Clock;
	double m_DesiredTime;
public:
	GameTime::GameTime();
	virtual GameTime::~GameTime();
	virtual sf::Time restart();
	virtual sf::Time getElapsedTime() const;
	double getDesiredTime() const;
};

#endif