#pragma once

#include<SFML/Graphics.hpp>
#include"option_listener.hpp"
#include <functional>
#include <string>


class generic_option : public sf::Text{
private:
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
		: sf::Text(string, font),
		listener(first_listener)
	{
		auto tmp = getGlobalBounds();
		setOrigin((tmp.width / 2) + tmp.left, (tmp.height / 2) + tmp.top);
		setPosition(position);
		setFillColor(sf::Color::Yellow);
		setOutlineColor(sf::Color::Blue);
	}

	void draw(sf::RenderWindow & window) {
		window.draw(*this);
	}

	void update() {}

	void set_listener(std::shared_ptr<option_listener> new_listener) { listener = new_listener; }

	void set_activation_function(std::function<void(void)> function) {
		activation_function = function;
	}

	void activate() { 
		listener->is_pressed("listener message");
		if (activation_function != nullptr) {
			activation_function();
		}
	}

	void set_selection() {
		setOutlineThickness(3);
	}

	void remove_selection() {
		setOutlineThickness(0);
	}
};