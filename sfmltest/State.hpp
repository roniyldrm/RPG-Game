#pragma once
#include "Player.hpp"

class State {
private:

protected:
	sf::RenderWindow* window;
	std::map<std::string, sf::Keyboard::Key>* supportedKeys;
	std::map<std::string, sf::Keyboard::Key> keybinds;
	bool quit;

	std::stack<State*>& states;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// resources
	std::map<std::string,sf::Texture> textures;

	//functions
	virtual void initKeyBinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>& states);
	virtual ~State();

	auto getQuit() const -> const bool&;

	virtual void updateMousePositions();

	void endState();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};