#pragma once
#include "State.h"

class GameState : public State{
private:
	

public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	// functions
	void update(const float& dt);
	void render(sf::RenderTarget* target);
	void updateKeybinds(const float& dt);
	void endState();
};

