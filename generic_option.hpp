#pragma once

#include<SFML/Graphics.hpp>
#include"option_listener.hpp"


class generic_option : public sf::Text{
private:
	option_listener * listener;

public:
	generic_option(
		const std::string & string,
		const sf::Font & font,
		const sf::Vector2f & position,
		option_listener * first_listener = nullptr
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

	//void set_listener(option_listener * new_listener) { listener = new_listener; }
	void activate() { listener->is_pressed(getString()); }

	void set_selection() {
		setOutlineThickness(3);
	}

	void remove_selection() {
		setOutlineThickness(0);
	}
};