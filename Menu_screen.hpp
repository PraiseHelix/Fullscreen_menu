#ifndef _MENU_SCREEN
#define _MENU_SCREEN

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <functional>
#include "text_option.hpp"

class menu_screen {
	sf::Text title;
	std::vector<std::shared_ptr<text_option>> options;
	unsigned int selected_option_index;
public:
	menu_screen(const std::string & text, const sf::Font & font, int windowwidth, int windowheight);
	void draw(sf::RenderWindow & window);
	void update(sf::RenderWindow & window);
	void activate_selected();
	void scroll_down();
	void scroll_up();

	template<typename T>
	void add(std::shared_ptr<T> & option) {
		options.push_back(option);
	}
};


#endif // !_MENU_SCREEN