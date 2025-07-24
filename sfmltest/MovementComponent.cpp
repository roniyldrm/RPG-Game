#include "MovementComponent.hpp"

MovementComponent::MovementComponent(float maxVelocity) : maxVelocity(maxVelocity){
}

MovementComponent::~MovementComponent() {
}

const sf::Vector2f& MovementComponent::getVelocity() {
	return velocity;
}

void MovementComponent::move(const sf::Vector2f& dir) {
	this->velocity.x = this->maxVelocity * dir.x;
	this->velocity.y = this->maxVelocity * dir.y;
}

void MovementComponent::update(const float& dt) {

}