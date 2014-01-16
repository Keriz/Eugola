/*
THIS PROJECT IS UNDER KERIZ' PROPERTY
Eugola - 2013
*/

/*
-StateManager.h-
Son travail est de coordonner et de gerer les différents etats du jeu.
*/

#ifndef STATEMANAGER
#define STATEMANAGER

#pragma region Include
#include <vector>
#include "State.h"
#include "GameTime.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextureManager.h"
#include "Exception.h"
#pragma endregion


class StateManager {
	std::vector<State*> states;
	State* m_CurrentState;
	sf::RenderWindow* m_WindowContext;
	TextureManager* m_TextureManager;
	Exception* m_EHandler;

public:
	StateManager::StateManager();
	StateManager::~StateManager();

	void bind(sf::RenderWindow*, TextureManager*, Exception*);

	//MANAGE
	void add_state(State* state);
	void remove_state(State* state);
	void set_current_state(State* state);

	//RENDER AND UPDATE
	void update(GameTime const& time);
	void render(GameTime const& time);
};

#endif