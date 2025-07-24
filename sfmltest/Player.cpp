#include "Player.hpp"

Player::Player(sf::Vector2f pos, sf::Texture* texture) {
	this->initVars();
	this->initComponents();
	this->createSprite(texture);
	this->setPosition(pos);
}

Player::~Player() {
}


void Player::initVars() {

}

void Player::initComponents() {
	this->createMovementComp(100.f);
}