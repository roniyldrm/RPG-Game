#pragma once
#include "GameState.h"
class Game {

private:
	// vars
	sf::RenderWindow* window;
	sf::Clock dtClock;

	std::optional<sf::Event> sfEvent;
	std::stack<State*> states;
	std::map<const char*, sf::Keyboard::Key> supportedKeys;

	float dt;

	// inits
	void initWindow();
	void initStates();
	void initKeys();
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

