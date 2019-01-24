#ifndef _text_option
#define _text_option

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <functional>

class menu_option : public sf::Text{
public:
	virtual void activate() = 0;
	virtual void draw_selection(sf::RenderWindow & window) = 0;
};



class text_option : public menu_option{
public:
	std::function< void() > on_activation;
	sf::RectangleShape indicator;
public:
//	text_option() {};

	text_option(
		const std::string & string,
		const sf::Vector2f & position,
		std::function<void()> on_activation,
		const int & charactersize,
		const sf::Font & font,
		const sf::Color & fillcolor = sf::Color::Yellow,
		const sf::Color & outlinecolor = sf::Color::Blue
	);

	void draw_selection(sf::RenderWindow & window);
	void activate();
};


class framerate_option : public text_option {
public:
	framerate_option(
		const std::string & string,
		const sf::Vector2f & position,
		const int & charactersize,
		const sf::Font & font,
		const sf::Color & fillcolor = sf::Color::Yellow,
		const sf::Color & outlinecolor = sf::Color::Blue
	):
		text_option(string, position,
			[this]() {
				setString("Framerate Limit	_");
				/*TODO: wait for input. if not number then break*/},
			charactersize, font, fillcolor, outlinecolor) {
	}
};


#endif