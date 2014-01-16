#include "World.h"

World::World()
{
	
}

World::~World()
{
	m_Window = 0;
}

void World::link_window(sf::RenderWindow* window)
{
	m_Window = window;
	m_Tilemap.link_window(window);
}

void World::loadContent(TextureManager* textureManager, Exception* eHandler)
{
	m_Tilemap.load_tiles(textureManager, eHandler);
}

void World::draw()
{
	m_Tilemap.draw();
}