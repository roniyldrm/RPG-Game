#include "State.h"
#include "GameState.h"

State::State(sf::RenderWindow* window) :
	window(window), quit(false)
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