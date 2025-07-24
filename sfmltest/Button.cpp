#include "Button.hpp"

Button::Button(float x, float y, float width, float height, sf::Font* font, const std::string& text ,
	const sf::Color& idleColor, const sf::Color& hoverColor, const sf::Color& activeColor) 
	: buttonState(BTN_IDLE), font(font), idleColor(idleColor), hoverColor(hoverColor), activeColor(activeColor) {
	
	this->shape.setPosition({ x,y });
	this->shape.setSize({ width, height });

	this->text = new sf::Text(*this->font, std::move(text));

	this->text->setFillColor(sf::Color::White);
	this->text->setCharacterSize(12);
	this->text->setPosition({
		this->shape.getPosition().x + (this->shape.getGlobalBounds().size.x / 2.f) - this->text->getGlobalBounds().size.x / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().size.y / 2.f) - this->text->getGlobalBounds().size.y / 2.f
	});
	this->shape.setFillColor(this->idleColor);

}

Button::~Button() {
	delete this->text;
}

const bool Button::isPressed() const{
	return (this->buttonState == BTN_ACTIVE);
}


void Button::update(const sf::Vector2f& mousePos) {
	
	this->buttonState = BTN_IDLE; //idle

	if (this->shape.getGlobalBounds().contains(mousePos)) {
		this->buttonState = BTN_HOVER; // hover

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			this->buttonState = BTN_ACTIVE; // active
		}
	}

	switch (this->buttonState) {
		case BTN_IDLE:
			this->shape.setFillColor(this->idleColor);
			break;

		case BTN_HOVER:
			this->shape.setFillColor(this->hoverColor);
			break; 

		case BTN_ACTIVE:
			this->shape.setFillColor(this->activeColor);
			break;

		default:
			this->shape.setFillColor(sf::Color::Red);
			break;
	}
}

void Button::render(sf::RenderTarget* target) {
	target->draw(this->shape);
	target->draw(*this->text);
}
