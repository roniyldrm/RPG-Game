#pragma once
#include "Entity.h"

class State {
private:

protected:
	sf::RenderWindow* window;
	std::map<const char*, sf::Keyboard::Key>* supportedKeys;
	std::map<const char*, sf::Keyboard::Key> keybinds;
	bool quit;

	// resources
	std::vector<sf::Texture> textures;

	//functions
	virtual void initKeyBinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<const char*, sf::Keyboard::Key>* supportedKeys);
	virtual ~State();

	const bool& getQuit() const;
	virtual void checkForQuit();


	virtual void endState() = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};