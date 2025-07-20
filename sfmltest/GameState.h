#pragma once
#include "State.h"

class GameState : public State{
private:
	Entity player;

	//functions
	void initKeyBinds();
public:
	GameState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys);
	virtual ~GameState();

	// functions
	void update(const float& dt);
	void render(sf::RenderTarget* target);
	void updateInput(const float& dt);
	void endState();
};

