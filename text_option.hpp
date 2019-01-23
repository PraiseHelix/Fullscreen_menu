#ifndef _text_option
#define _text_option

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <functional>

class text_option : public sf::Text {
	std::function< void() > on_activation;
	sf::RectangleShape indicator;
public:
	text_option() {};

	text_option(
		const std::string & string,
		const sf::Vector2f & position,
		std::function<void()> on_activation,
		const int & charactersize,
		const sf::Font & font,
		const sf::Color & fillcolor = sf::Color::Yellow,
		const sf::Color & outlinecolor = sf::Color::Blue
	);
	void drawselection(sf::RenderWindow & window);
	void activate();
};

#endif