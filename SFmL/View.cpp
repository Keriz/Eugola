#include "View.h"

View::View()
{

}


View::~View()
{
}

void View::link_window(sf::RenderWindow* window) {
	m_WindowContext = window;
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

void View::draw()
{
	m_WindowContext->draw(m_CursorSprite);
}