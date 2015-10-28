#include "Engine.h"
#include <cmath>
#include <assert.h>



Engine::Engine()
{

}

void Engine::init()
{
	setLastExceptionCode(0);

	m_EHandler.bind_engine(this);

	m_Window = new sf::RenderWindow(sf::VideoMode(800, 608), "Eugola");

	//m_Window->setFramerateLimit(60);

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
	double const desiredTime = m_GameTime.getDesiredTime();

	while(m_Window->isOpen())
	{
		double frameTime = m_GameTime.restart().asSeconds();

		//display FPS
		float actualTime = frameTime;
		int fps = 1 / actualTime;
		m_Window->setTitle(std::to_string(fps));

		while (frameTime > 0.0)
		{
			float deltaTime = float(fmin(frameTime, desiredTime));

			m_StateManager.update(m_GameTime);

			frameTime -= deltaTime;
		}

		m_StateManager.render(m_GameTime);
	}

}

void Engine::write_error(const char* type, const char* what)
{
	m_EHandler.write(type, what);
}

void Engine::exit_now()
{
	m_Window->close();
}