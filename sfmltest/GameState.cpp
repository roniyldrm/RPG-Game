#pragma once
#include "GameState.hpp"


GameState::GameState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>& states)
	: State(window, supportedKeys, states) {
	this->initKeyBinds();
	this->initTextures();
	this->initPlayers();
}

GameState::~GameState() {
	delete this->player;
}

void GameState::update(const float& dt) {
	this->updateMousePositions();

	this->updateInput(dt);
	
	this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target = nullptr) {
	if (!target)
		target = this->window;
	
	this->player->render(target);
}

void GameState::updateInput(const float& dt) {


	if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(dt, 0.f, 1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move(dt, 0.f, -1.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();

}
void GameState::initPlayers() {
	this->player = new Player(sf::Vector2f{0.f,0.f}, &this->textures["PLAYER_IDLE"]);
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

void GameState::initTextures() {
	if (!this->textures["PLAYER_IDLE"].loadFromFile("Resources/Images/Sprites/Player/player_sprite_idle.png")){
		throw("ERROR::GAME_STATE::COULD_NOT_LOAD_IDLE_TEXTURE");
	}
}



