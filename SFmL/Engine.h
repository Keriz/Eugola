/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-Engine.h-
Classe du moteur permettant au jeu de fonctionner. //TODO
*/

#ifndef ENGINE
#define ENGINE

#pragma region Include
#include "StateManager.h"
#include "GameplayState.h"
#include "TextureManager.h"
#include "Exception.h"
#include <SFML/Graphics.hpp>
#pragma endregion

class Engine {
	int m_LastExceptionCode;
	sf::RenderWindow* m_Window;
	TextureManager m_TextureManager;
	Exception m_EHandler;
	GameTime m_GameTime;
	StateManager m_StateManager;
public:
	Engine::Engine();
	Engine::~Engine();
	void run();
	void init();
	void setLastExceptionCode(const int exceptionCode){m_LastExceptionCode = exceptionCode; };
	void exit_now();
	int const getLastExceptionCode(){return m_LastExceptionCode;};
	void write_error(const char*, const char*);
};
#endif