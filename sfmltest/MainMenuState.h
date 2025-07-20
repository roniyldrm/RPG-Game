#pragma once
#include "GameState.h"
#include "Button.h"

class MainMenuState : public State{
private:
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, Button*> buttons;

	// inits
	void initKeyBinds();
	void initFonts();
	void initButtons();
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys);
	virtual ~MainMenuState();

	// functions
	void update(const float& dt);
	void updateInput(const float& dt);
	void updateButtons();
	void endState();
	void renderButtons(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

