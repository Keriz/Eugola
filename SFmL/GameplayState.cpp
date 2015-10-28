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
	m_View.link_window(m_WindowContext);
}

void GameplayState::load_content()
{
	//coucou = m_TextureManager->registerTexture("test", "img/PreviewSmall_1.png");
	//coudcou.setTexture(coucou);

	m_View.register_cursor(m_WindowContext, m_TextureManager, m_EHandler);
	m_World.loadContent(m_TextureManager, m_EHandler);

}

void GameplayState::render(GameTime const& gameTime)
{
	m_WindowContext->clear();
	m_World.draw();
	m_View.draw();
	//lumière
	//shader
//	m_WindowContext->draw(coudcou);
	m_WindowContext->display();
}

void GameplayState::update(GameTime const& gameTime)
{
	sf::Event event;

	m_View.update_cursor(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*m_WindowContext) ) );

	while (m_WindowContext->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_WindowContext->close();
			}
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_View.move(sf::Keyboard::Up, gameTime.getElapsedTime());
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_View.move(sf::Keyboard::Down, gameTime.getElapsedTime());
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_View.move(sf::Keyboard::Right, gameTime.getElapsedTime());
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_View.move(sf::Keyboard::Left, gameTime.getElapsedTime());
	}

	m_View.update_position();

}