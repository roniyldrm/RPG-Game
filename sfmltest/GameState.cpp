#pragma once
#include "GameState.h"


GameState::GameState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys)
	: State(window, supportedKeys) 
{
	this->initKeyBinds();
}

GameState::~GameState() {

}

void GameState::update(const float& dt) {
	//std::println("hello gamestate");
	this->updateMousePositions();

	this->updateInput(dt);
	
	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target = nullptr) {
	if (!target)
		target = this->window;
	
	this->player.render(target);
}

void GameState::updateInput(const float& dt) {
	this->checkForQuit();

	if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player.move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player.move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player.move(dt, 0.f, 1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player.move(dt, 0.f, -1.0f);

}
void GameState::initKeyBinds() {
	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2) {
			this->keybinds[std::move(key)] = this->supportedKeys->at(key2);
		}
	}
	ifs.close();
}

void GameState::endState() {
	std::println("ending states");
}


