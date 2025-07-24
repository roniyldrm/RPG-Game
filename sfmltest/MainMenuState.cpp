#pragma once
#include "MainMenuState.hpp"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>& states)
	: State(window, supportedKeys, states){
	
	this->initVars();
	this->initBackground();
	this->initFonts();
	this->initKeyBinds();
	this->initButtons();
}

MainMenuState::~MainMenuState() {

	for (auto& btn : buttons) {
		delete btn.second;
	}

}

void MainMenuState::update(const float& dt) {
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::render(sf::RenderTarget* target = nullptr) {
	if (!target)
		target = this->window;
	
	target->draw(this->background);
	this->renderButtons(target);

	//! remove later 
	//! mouse pos logging on cursor
	sf::Text mouseText{this->font};
	mouseText.setPosition({ this->mousePosView.x, this->mousePosView.y - 50 });
	mouseText.setCharacterSize(12);
	mouseText.setString(std::format("({},{})", this->mousePosView.x, this->mousePosView.y));
	target->draw(mouseText);
	//! mouse pos logging on cursor
}

void MainMenuState::updateInput(const float& dt) {


}
void MainMenuState::updateButtons() {
	// update buttons in state + calls associated functions
	for (auto& btn : this->buttons) {
		btn.second->update(this->mousePosView);
	}
	

	if (this->buttons["GAME_STATE"]->isPressed()) {
		auto&& newGS = new GameState(this->window, this->supportedKeys, this->states);
		this->states.push(std::forward<decltype(newGS)>(newGS));
	}

	if (this->buttons["EXIT_STATE"]->isPressed()) {
		this->quit = true;
	}

}
void MainMenuState::initKeyBinds() {
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2) {
			this->keybinds[std::move(key)] = this->supportedKeys->at(key2);
		}
	}
	
	ifs.close();
}

void MainMenuState::initBackground() {
	this->background.setSize({ static_cast<float>(window->getSize().x),static_cast<float>(window->getSize().y) });

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png")) {
		throw("ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE");
	}
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts() {
	if (!this->font.openFromFile("Fonts/IntelOneMono.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT OPEN THE FONT");
	}
}

void MainMenuState::initVars() {

}

void MainMenuState::initButtons() {
	this->buttons["GAME_STATE"] = new Button(150, 100, 150, 40, &this->font, "Start New Game",
		sf::Color{ 70, 70, 70, 200 }, sf::Color{ 150, 150, 150, 255 }, sf::Color{ 20, 20, 20, 200 });

	this->buttons["SETTINGS"] = new Button(150, 200, 150, 40, &this->font, "Settings",
		sf::Color{ 70, 70, 70, 200 }, sf::Color{ 150, 150, 150, 255 }, sf::Color{ 20, 20, 20, 200 });

	this->buttons["EXIT_STATE"] = new Button(150, 300, 150, 40, &this->font, "Quit",
		sf::Color{ 70, 70, 70, 200 }, sf::Color{ 150, 150, 150, 255 }, sf::Color{ 20, 20, 20, 200 });
}

void MainMenuState::renderButtons(sf::RenderTarget* target = nullptr) {
	for (auto& btn : this->buttons) {
		btn.second->render(target);
	}
}


