#include "View.h"

View::View()
{
}


View::~View()
{
}

void View::link_window(sf::RenderWindow* window) {
	m_WindowContext = window;
	m_View.setViewport(sf::FloatRect(0, 0, 1, 1));
	m_View.setCenter(sf::Vector2f(1200, 912));
	m_View.setSize(sf::Vector2f(800, 608));
	// init view
}

void View::register_cursor(sf::RenderWindow * windowContext, TextureManager * textureManager, Exception * eHandler) //peut être que je vais virer eHandler (l'argument)
{
	windowContext->setMouseCursorVisible(false);
	m_CursorTexture = textureManager->registerTexture("cursor", "img/curseur.png");
	m_CursorSprite.setTexture(m_CursorTexture);
}

void View::update_cursor(const sf::Vector2<float> mousePosition) {
	m_CursorSprite.setPosition(mousePosition);
}

void View::move(sf::Keyboard::Key key, sf::Time deltaTime) {
	float speed = 4; // pour tester seulement

	switch (key){
		case sf::Keyboard::Up :
		{
			m_View.move(0, speed * 1.0 / 120.0);//deltaTime.asMilliseconds());
			break;
		}

		case sf::Keyboard::Down :
		{
			m_View.move(0, -speed * 1.0 / 120.0);
			break;
		}

		case sf::Keyboard::Right :
		{
			m_View.move(-speed * 1.0 / 120.0, 0);
			break;
		}

		case sf::Keyboard::Left :
		{
			m_View.move(speed * 1.0 / 120.0, 0);
			break;
		}
	}

}

void View::draw()
{
	m_WindowContext->draw(m_CursorSprite);
}

void View::update_position()
{
	m_WindowContext->setView(m_View);
}