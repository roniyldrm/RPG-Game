#pragma once
#include "MovementComponent.hpp"

class Entity {

private:
	void initVars();

protected:
	sf::Sprite* sprite;
	sf::Texture* texture;
	MovementComponent* movementComp;

public:
	Entity();
	virtual ~Entity();

	// component functions
	void createSprite(sf::Texture* texture);
	void createMovementComp(const float maxVel);

	// functions
	virtual void setPosition(sf::Vector2f& pos);
	virtual void move(const float& dt, const float dir_x, const float dir_y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

