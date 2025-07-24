#pragma once
#include "GameState.hpp"
#include "Button.hpp"

class MainMenuState : public State{
private:
	sf::Font font;
	sf::RectangleShape background;
	sf::Texture backgroundTexture;

	std::map<std::string, Button*> buttons;

	// inits	
	void initBackground();
	void initVars();
	void initKeyBinds();
	void initFonts();
	void initButtons();
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>& states);
	virtual ~MainMenuState();

	// functions
	void update(const float& dt);
	void updateInput(const float& dt);
	void updateButtons();
	void renderButtons(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

