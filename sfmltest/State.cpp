#include "State.h"
#include "GameState.h"

State::State(sf::RenderWindow* window, std::map<const char*, sf::Keyboard::Key>* supportedKeys) 
	: window(window), quit(false), supportedKeys(supportedKeys)
{

}

State::~State() {
}

const bool& State::getQuit() const {
	return this->quit;
}

void State::checkForQuit() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		this->quit = true;
	}
}