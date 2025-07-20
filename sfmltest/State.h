#pragma once
#include "Entity.h"

class State {
private:

protected:
	sf::RenderWindow* window;
	std::map<std::string, sf::Keyboard::Key>* supportedKeys;
	std::map<std::string, sf::Keyboard::Key> keybinds;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// resources
	std::vector<sf::Texture> textures;

	//functions
	virtual void initKeyBinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys);
	virtual ~State();

	auto getQuit() const -> const bool&;
	virtual void checkForQuit();

	virtual void updateMousePositions();

	virtual void endState() = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};