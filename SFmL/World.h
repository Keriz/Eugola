/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-World.h-
G�re affichage de: TODO
			-carte
			-joueur
			-entit�es
			-background
G�re les collisions entre le joueur et la carte. Entre la carte et les entit�es, et entre les entit�es et le joueur. TODO
G�re l'IA. TODO
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