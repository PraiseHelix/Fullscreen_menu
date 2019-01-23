#ifndef _MENU_SCREEN
#define _MENU_SCREEN

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "text_option.hpp"

class menu_screen {
	sf::Text title;
	std::vector<text_option> options;
	text_option selected_option; //TODO: smart pointers?
public:
	menu_screen(const std::string & text, const sf::Font & font, int windowwidth, int windowheight);
	void add(text_option & option);
	void draw(sf::RenderWindow & window);
	void update(sf::RenderWindow & window);
	void activate_selected();
	void scroll_down();
};


#endif // !_MENU_SCREEN