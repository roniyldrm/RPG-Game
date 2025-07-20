#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <print>

enum buttonStates { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button {

private:
	
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text* text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;


public:
	Button(float x, float y, float width, float height, sf::Font* font, const std::string& text,
		const sf::Color& idleColor, const sf::Color& hoverColor, const sf::Color& activeColor);
	virtual ~Button();

	// accessors
	const bool isPressed() const;

	// functions
	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget* target);

};

