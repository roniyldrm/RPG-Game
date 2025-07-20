#pragma once
#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>& states)
	: State(window, supportedKeys, states){
	
	this->initFonts();
	this->initKeyBinds();

	this->buttons["GAME_STATE"] = new Button( 150, 50, 100, 30, &this->font, "Start New Game",
			sf::Color{70, 70, 70, 200}, sf::Color{ 150, 150, 150, 255}, sf::Color{ 20, 20, 20, 200 });

	this->buttons["EXIT_STATE"] = new Button(150, 150, 100, 30,  &this->font, "Quit",
		sf::Color{ 70, 70, 70, 200 }, sf::Color{ 150, 150, 150, 255 }, sf::Color{ 20, 20, 20, 200 });

	this->background.setSize({ static_cast<float>(window->getSize().x),static_cast<float>(window->getSize().y) });
	this->background.setFillColor(sf::Color::Cyan);

	
}

MainMenuState::~MainMenuState() {

	for (auto& btn : buttons) {
		delete btn.second;
	}

}

void MainMenuState::update(const float& dt) {
	//std::println("hello MainMenuState");
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();

	system("cls");
	std::println("x :{} y:{}", this->mousePosView.x, this->mousePosView.x);
}

void MainMenuState::render(sf::RenderTarget* target = nullptr) {
	if (!target)
		target = this->window;
	
	target->draw(this->background);
	this->renderButtons(target);
}

void MainMenuState::updateInput(const float& dt) {
	this->checkForQuit();

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

void MainMenuState::initFonts() {
	if (!this->font.openFromFile("Fonts/IntelOneMono.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT OPEN THE FONT");
	}
}

void MainMenuState::initButtons() {

}

void MainMenuState::endState() {
	std::println("ending states");
}

void MainMenuState::renderButtons(sf::RenderTarget* target = nullptr) {
	for (auto& btn : this->buttons) {
		btn.second->render(target);
	}
}


