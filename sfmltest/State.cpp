#include "State.hpp"
#include "GameState.hpp"

State::State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>& states)
	: window(window), quit(false), supportedKeys(supportedKeys), states(states){

}

State::~State() {
}

auto State::getQuit() const -> const bool& {
	return this->quit;
}

void State::endState() {
	this->quit = true;
}


void State::updateMousePositions() {
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}