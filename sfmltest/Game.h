#pragma once
#include "GameState.h"
class Game {

private:
	// vars
	sf::RenderWindow* window;
	std::optional<sf::Event> sfEvent;
	sf::Clock dtClock;
	std::stack<State*> states;
	float dt;

	// inits
	void initWindow();
	void initStates();
public:

	// ctors/dtors
	Game();
	virtual ~Game();

	// other functions
	void endApplication();

	// update
	void update();
	void updateDt();
	void updateSFMLevents();

	// render
	void render();

	// core
	void run();
};

