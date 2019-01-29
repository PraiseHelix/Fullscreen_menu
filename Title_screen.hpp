#pragma once
#include <SFML/Graphics.hpp>
#include "menu_screen.hpp"
#include "generic_option.hpp"

class title_screen :public menu_screen {
public:
	title_screen(sf::RenderWindow & window, option_listener * listener): menu_screen(window) {
		font.loadFromFile("Pokemon Solid.ttf");
		auto tmp_size = window.getSize();

		//Title text
		title.setString("Pocket-Animals");
		title.setFont(font);
		title.setOrigin((title.getGlobalBounds().width/2)+title.getGlobalBounds().left, (title.getGlobalBounds().height / 2) + title.getGlobalBounds().top );
		title.setPosition(float(tmp_size.x/2), 100);
		title.setFillColor(sf::Color::Green);

		//the menu options
		auto start_option = std::make_shared<generic_option>("Start", font, sf::Vector2f(float(tmp_size.x / 2), 300), listener);
		auto settings_option = std::make_shared<generic_option>("Settings", font, sf::Vector2f(float(tmp_size.x / 2), 400), listener);
		auto quit_option = std::make_shared<generic_option>("Quit", font, sf::Vector2f(float(tmp_size.x / 2), 500), listener);
		//adding to the menu
		options.push_back(start_option);
		options.push_back(settings_option);
		options.push_back(quit_option);
	}
};