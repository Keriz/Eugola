#include "StateManager.h"

StateManager::StateManager()
{
	m_CurrentState = 0;
}

StateManager::~StateManager()
{
	for (int i = 0; i < states.size() ; ++i)
	{
		delete states[i];
		states[i] = 0;
	}
	m_CurrentState = 0;
	m_WindowContext = 0;
	m_TextureManager= 0;
}

void StateManager::bind(sf::RenderWindow* windowContext, TextureManager* textureManager, Exception* eHandler)
{
	m_WindowContext = windowContext;
	m_TextureManager = textureManager;
	m_EHandler = eHandler;
}

void StateManager::set_current_state(State* state)
{
	if (m_CurrentState != 0)
		m_CurrentState->pause();
	m_CurrentState = state;
}

void StateManager::add_state(State* state)
{
	states.push_back(state);
	set_current_state(states.back());
	m_CurrentState->initialize(m_WindowContext, m_TextureManager, m_EHandler);
	m_CurrentState->load_content();
}

void StateManager::render(GameTime const& gameTime)
{
	m_CurrentState->render(gameTime);
}

void StateManager::update(GameTime const& gameTime)
{
	m_CurrentState->update(gameTime);
}
