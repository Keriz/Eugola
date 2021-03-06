/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-GameplayState.h-        _
Classe du jeu principal /!\
					   /!!!\
Fichier important	  /_____\
*/

#pragma region Include
#include <SFML\Graphics.hpp>
#include "BaseState.h"
#include <iostream>
#include "World.h"
#pragma endregion

class GameplayState : public BaseState {
	World m_World;

#pragma region Textures

sf::Texture coucou;

#pragma endregion

#pragma region Sprites

sf::Sprite coudcou;

#pragma endregion
	
public:
	GameplayState::GameplayState();
	virtual GameplayState::~GameplayState();
	virtual void render(GameTime const& gameTime);
	virtual void update(GameTime const& gameTime);
	virtual void initialize(sf::RenderWindow*,TextureManager*,Exception*);
	virtual void load_content();
	virtual void pause();
};