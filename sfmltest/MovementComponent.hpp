#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <optional>
#include <fstream>
#include <sstream>
#include <vector>
#include <print>
#include <ctime>
#include <stack>
#include <map>

class MovementComponent {
private:
	float maxVelocity;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;

	//inits
public:
	MovementComponent(float maxVelocity);
	virtual ~MovementComponent();
	

	const sf::Vector2f& getVelocity();

	void move(const sf::Vector2f& dir);
	void update(const float& dt);
};

