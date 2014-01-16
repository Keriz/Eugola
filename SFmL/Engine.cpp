#include "Engine.h"

Engine::Engine()
{
	setLastExceptionCode(0);

	m_EHandler.bind_engine(this);

	m_Window = new sf::RenderWindow(sf::VideoMode(800,608), "Eugola");

	m_TextureManager.bind(&m_EHandler);

	m_StateManager.bind(m_Window, &m_TextureManager, &m_EHandler);

	State *g(0);

	g = new GameplayState();

	m_StateManager.add_state(g);
}

Engine::~Engine()
{
	delete m_Window;
}

void Engine::run()
{
	while(m_Window->isOpen())
	{
		float actualTime = m_GameTime.restart().asSeconds();
		int fps = 1 / actualTime;
		m_Window->setTitle(std::to_string(fps));
		m_StateManager.render(m_GameTime);
		m_StateManager.update(m_GameTime);
	}

}

void Engine::exit_now(int exceptionLevel,char* exceptionMessage)
{
	m_Window->close();
	const char* copy = exceptionMessage;
	m_ExitMessage = std::string(exceptionMessage);
}