#pragma once
#include "State.hpp"

class GameState : public State{
private:
	Player* player;

	//functions
	void initPlayers();
	void initKeyBinds();
	void initTextures();
public:
	GameState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>& states);
	virtual ~GameState();

	// functions
	void update(const float& dt);
	void render(sf::RenderTarget* target);
	void updateInput(const float& dt);
};

