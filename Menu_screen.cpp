#include "Menu_screen.hpp"

menu_screen::menu_screen(const std::string & text, const sf::Font & font, int windowwidth, int windowheight) :
	title(text, font),
	options(options) {
	//title
	title.setFillColor(sf::Color::Yellow);
	title.setOutlineColor(sf::Color::Blue);
	title.setOutlineThickness(3);
	title.setCharacterSize(50);
	title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	title.setPosition(sf::Vector2f(float(windowwidth / 2), float(windowheight / 6)));
}

void menu_screen::add(text_option & option) {
	options.push_back(option);
	if (options.size() == 1) {
		selected_option = options[0];
	}
}

void menu_screen::draw(sf::RenderWindow & window) {
	window.draw(title);
	for (auto & option : options) {
		window.draw(option);
	}
	selected_option.drawselection(window);
}

void menu_screen::update(sf::RenderWindow & window) {
	//TODO: niet efficent? kan ook in draw functie
	for (auto & option : options) {
		if (option.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
			selected_option = option;
		}
	}
}

void menu_screen::activate_selected() {
	selected_option.activate();
}

void menu_screen::scroll_down() {

}