#include "Entity.hpp"

Entity::Entity() {
	this->initVars();
}

Entity::~Entity() {
	delete this->sprite;
}

void Entity::initVars() {
	this->texture = nullptr;
	this->sprite = nullptr;
	this->movementComp = nullptr;
}

void Entity::setPosition(sf::Vector2f& pos) {
	if (this->sprite)
		this->sprite->setPosition(pos);
}

void Entity::createSprite(sf::Texture* texture) {
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
}

void Entity::createMovementComp(const float maxVel) {
	this->movementComp = new MovementComponent(maxVel);
}

void Entity::move(const float& dt, const float dir_x, const float dir_y) {
	if (this->sprite && this->movementComp) {
		this->movementComp->move({ dir_x,dir_y }); // Sets velocity
		this->sprite->move({ this->movementComp->getVelocity() * dt}); // uses velocity
	}
}

void Entity::update(const float& dt) {

}

void Entity::render(sf::RenderTarget* target) {
	if (this->sprite) {
		target->draw(*this->sprite);
	}
}
