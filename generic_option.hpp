#pragma once

#include<SFML/Graphics.hpp>
#include"option_listener.hpp"
#include <functional>
#include <string>

class generic_option {
private:
	sf::Text text;
	sf::Sprite button;
	std::shared_ptr<option_listener> listener;
	std::function<void(void)> activation_function = nullptr;
	//std::string to_listener;

public:
	generic_option(
		const std::string & string,
		const sf::Font & font,
		const sf::Vector2f & position,
		std::shared_ptr<option_listener> first_listener = nullptr
	)
		: text(string, font),
		listener(first_listener)
	{
		auto tmp = text.getGlobalBounds();
		text.setOrigin((tmp.width / 2) + tmp.left, (tmp.height / 2) + tmp.top);
		text.setPosition(position);
		text.setFillColor(sf::Color::Yellow);
		text.setOutlineColor(sf::Color::Blue);
		text.setOutlineThickness(3);

		//button
		auto texture(new sf::Texture);
		texture->loadFromFile("menuButton.png");
		button.setTexture(*texture);
		button.setOrigin((button.getGlobalBounds().width / 2) + button.getGlobalBounds().left, (button.getGlobalBounds().height / 2) + button.getGlobalBounds().top);
		button.setPosition(text.getPosition());
		button.setScale(float(0.4), float(0.3));
	}

	void onCall() {};
	void onStart() {};
	void onCollistion() {};
	void onInteract() {};
	void update() {};


	void draw(sf::RenderWindow & window) {
		window.draw(button);
		window.draw(text);
	}

	sf::Rect<float> getGlobalBounds() {
		return button.getGlobalBounds();
	}

	void setString(std::string string) {
		text.setString(string);
	}

	void set_listener(std::shared_ptr<option_listener> new_listener) { listener = new_listener; }

	void set_activation_function(std::function<void(void)> function) {
		activation_function = function;
	}

	void activate() { 
		//listener->is_pressed("listener indicator");
		if (activation_function) {
			activation_function();
		}
	}

	void set_selection() {
		text.setOutlineColor(sf::Color::Red);
	}

	void remove_selection() {
		text.setOutlineColor(sf::Color::Blue);
	}
};