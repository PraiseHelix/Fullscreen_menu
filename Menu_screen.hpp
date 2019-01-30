#pragma once
#include "generic_option.hpp"
#include "SFML/Graphics.hpp"

class menu_screen {
private:
	sf::RenderWindow & window;
	sf::Text title;
	std::vector<std::shared_ptr<generic_option>> options;
	unsigned int selected_index = 0;
public:

	menu_screen(sf::RenderWindow & window, const std::string & title_text, const sf::Font & font): window(window), options(options) {
		auto tmp_size = window.getSize();

		title.setString(title_text);
		title.setFont(font);
		title.setOrigin((title.getGlobalBounds().width / 2) + title.getGlobalBounds().left, (title.getGlobalBounds().height / 2) + title.getGlobalBounds().top);
		title.setPosition(float(tmp_size.x / 2), 100);
		title.setFillColor(sf::Color::Green);
	}

	void push_back(std::shared_ptr<generic_option> option) {
		options.push_back(option);
	}

	//check's if mouse is over an option. if true, option is selected.
	void on_update() {
		for (unsigned int i = 0; i < options.size(); i++) {
			options[i]->remove_selection();
			options[i]->update();
			if (options[i]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
				selected_index = i;
			}
		}
		options[selected_index]->set_selection();
	}

	//draw's the title and all options
	void on_draw() {
		window.draw(title);
		for (auto & option : options) {
			//window.draw(*option);
			option->draw(window);
		}
	}

	//activates the selected option
	void on_activate() { 
		options[selected_index]->activate();
	}

	//scroll up in the menu (decrement the selected_index)
	void scroll_up() {
		if (selected_index == 0) {
			selected_index = options.size() - 1;
			return;
		}
		selected_index--;
	}
	//scroll down in the menu. (increment the selected_index)
	void scroll_down() {
		if (++selected_index < options.size()) {
			return;
		}
		selected_index = 0;
	}
};