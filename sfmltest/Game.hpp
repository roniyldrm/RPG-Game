#pragma once

#include "MainMenuState.hpp"
class Game {

private:
	// vars
	sf::RenderWindow* window;
	sf::ContextSettings window_settings;
	sf::Clock dtClock;
	bool fullscreen;
	std::optional<sf::Event> sfEvent;
	std::vector<sf::VideoMode> videoModes;
	std::stack<State*> states;

	std::map<std::string, sf::Keyboard::Key> supportedKeys;

	float dt;

	// inits
	void initVars();
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

