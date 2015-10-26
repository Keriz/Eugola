#include "GameplayState.h"

GameplayState::GameplayState()
{

}

GameplayState::~GameplayState()
{
	m_WindowContext = 0;
	m_TextureManager = 0;
	m_EHandler = 0;
}

void GameplayState::pause()
{

}

void GameplayState::initialize(sf::RenderWindow* windowContext, TextureManager* textureManager, Exception* eHandler)
{
	m_WindowContext = windowContext;
	m_TextureManager = textureManager;
	m_EHandler = eHandler;
	m_World.link_window(m_WindowContext);
}

void GameplayState::load_content()
{
	//coucou = m_TextureManager->registerTexture("test", "img/PreviewSmall_1.png");
	//coudcou.setTexture(coucou);

	m_World.loadContent(m_TextureManager, m_EHandler);
}

void GameplayState::render(GameTime const& gameTime)
{
	m_WindowContext->clear();
	m_World.draw();
	//lumière
	//shader
//	m_WindowContext->draw(coudcou);
	m_WindowContext->display();
}

void GameplayState::update(GameTime const& gameTime)
{
	sf::Event event;

	while (m_WindowContext->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_WindowContext->close();
			}
		}

	
}