#include "Menu_screen.hpp"

menu_screen::menu_screen(const std::string & text, const sf::Font & font, int windowwidth, int windowheight) :
	title(text, font),
	selected_option_index(0){
	//title_settings
	title.setFillColor(sf::Color::Yellow);
	title.setOutlineColor(sf::Color::Blue);
	title.setOutlineThickness(3);
	title.setCharacterSize(50);
	title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	title.setPosition(sf::Vector2f(float(windowwidth / 2), float(windowheight / 6)));
}

void menu_screen::draw(sf::RenderWindow & window) {
	window.draw(title);
	for (auto & option : options) {
		window.draw(*option);
	}
	options[selected_option_index]->draw_selection(window);
}

void menu_screen::update(sf::RenderWindow & window) {
	for(unsigned int i = 0; i < options.size(); i++){
		if (options[i]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
			selected_option_index = i;
		}
	}
}

void menu_screen::activate_selected() {
	options[selected_option_index]->activate();
}

void menu_screen::scroll_down() {
	if (selected_option_index == 0) {
		selected_option_index = options.size() - 1;
		return;
	}
	selected_option_index--;
}

void menu_screen::scroll_up() {
	if (++selected_option_index < options.size()) {
		return;
	}
	selected_option_index = 0;
}
