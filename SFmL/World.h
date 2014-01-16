/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-World.h-
Gère affichage de: TODO
			-carte
			-joueur
			-entitées
			-background
Gère les collisions entre le joueur et la carte. Entre la carte et les entitées, et entre les entitées et le joueur. TODO
Gère l'IA. TODO
*/

#ifndef WORLD
#define WORLD

#pragma region Include
#include "Tilemap.h"
#include "TextureManager.h"
#pragma endregion

class World {
	Tilemap	m_Tilemap;
	sf::RenderWindow* m_Window;
public:
	World::World();
	World::~World();
	void link_window(sf::RenderWindow* window);
	void loadContent(TextureManager*, Exception*);
	void draw();
};

#endif