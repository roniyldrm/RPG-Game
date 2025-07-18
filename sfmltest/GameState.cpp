#pragma once
#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window) {

}

GameState::~GameState() {

}

void GameState::update(const float& dt) {
	std::println("hello gamestate");
	this->updateKeybinds(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		std::println("key a pressed");
	}
}

void GameState::render(sf::RenderTarget* target = nullptr) {

}

void GameState::updateKeybinds(const float& dt) {
	this->checkForQuit();
}

void GameState::endState() {
	std::println("ending states");
}


