#include "text_option.hpp"

text_option::text_option(
	const std::string & string,
	const sf::Vector2f & position,
	std::function< void() > on_activation,
	const int & charactersize,
	const sf::Font & font,
	const sf::Color & fillcolor,
	const sf::Color & outlinecolor
) :
	//menu_option(string, font),
	on_activation(on_activation){
	setString(string);
	setFont(font);
	setCharacterSize(charactersize);
	setFillColor(fillcolor);
	setOutlineColor(outlinecolor);
	setOutlineThickness(3);
	setOrigin(getGlobalBounds().width / 2, 0);
	setPosition(position);

	//selection indicator
	indicator.setSize(sf::Vector2f(30, 30));
	indicator.setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	indicator.setPosition(
		getPosition().x - 50,
		getPosition().y + (getGlobalBounds().height / 2)
	);
}

void text_option::draw_selection(sf::RenderWindow & window) {
	window.draw(indicator);
}

void text_option::activate() {
	on_activation();
}
