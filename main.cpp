#include <iostream>
#include <SFML/Graphics.hpp>
#include "text_option.hpp"
#include <array>
#include <string>
#include <functional>
#include <vector>
#include <list>
#include "Menu_screen.hpp"


//TODO: menu handler. nodig voor het kunnen scrollen.
//TODO: smart pointers?
int main(){
	int windowwidth = 800;
	int windowheight = 600;
	int frameratelimit = 60;

	sf::RenderWindow window(sf::VideoMode(windowwidth, windowheight), "Main_Window");
	window.setFramerateLimit(frameratelimit);

	
	sf::Font Titlefont;
	Titlefont.loadFromFile("Pokemon Solid.ttf");
	
	menu_screen start_screen(std::string("Pocket-Animals"), Titlefont, windowwidth, windowheight);
	menu_screen settings_screen(std::string("Settings"), Titlefont, windowwidth, windowheight);
	menu_screen controls_screen(std::string("Controls"), Titlefont, windowwidth, windowheight);
	menu_screen* current_screen = &start_screen;

	//Title screen
	text_option newgame("New Game", sf::Vector2f(float(windowwidth / 2), 200), []() {std::cout << "New_game_event";}, 30, Titlefont, sf::Color::Yellow, sf::Color::Blue);
	text_option loadgame("Load Game", sf::Vector2f(float(windowwidth / 2), 300), []() {std::cout << "Load_game_event"; }, 30, Titlefont);
	text_option settings("Settings", sf::Vector2f(float(windowwidth / 2), 400), [&current_screen, &settings_screen]() {std::cout << "Settings_event"; current_screen = &settings_screen; }, 30, Titlefont);
	text_option quit("Quit", sf::Vector2f(float(windowwidth / 2), 500), [&window]() {std::cout << "Quit_event"; window.close(); }, 30, Titlefont);

	start_screen.add(newgame);
	start_screen.add(loadgame);
	start_screen.add(settings);
	start_screen.add(quit);
	
	//Settings screen
	text_option settings_back("Back", sf::Vector2f(float(windowwidth / 2), 500), [&current_screen, &start_screen]() {current_screen = &start_screen; }, 30, Titlefont);
	text_option text_framerate("Framerate Limit	" + std::to_string(frameratelimit), sf::Vector2f(float(windowwidth / 2), 200),
		[&frameratelimit]() {/*TODO: framerate kunnen instellen. nog geen idee hoe set string kan ik niet zo gebruiken get set functie maken in*/ }, 30, Titlefont);
	text_option controls_option("Controls", sf::Vector2f(float(windowwidth / 2), 400), [&current_screen, &controls_screen]() {current_screen = &controls_screen; }, 30, Titlefont);
	
	settings_screen.add(settings_back);
	settings_screen.add(text_framerate);
	settings_screen.add(controls_option);

	//Controls Screen
	text_option left_setting("Left", sf::Vector2f(float(windowwidth / 3), 200), []() {}, 30, Titlefont);
	text_option right_setting("Right", sf::Vector2f(float(windowwidth / 3), 200), []() {}, 30, Titlefont);
	text_option up_setting("Up", sf::Vector2f(float(windowwidth / 3), 200), []() {}, 30, Titlefont);
	text_option down_setting("Down", sf::Vector2f(float(windowwidth / 3), 200), []() {}, 30, Titlefont);

	while (window.isOpen()) {
		window.clear();

		current_screen->draw(window);

		window.display();
		
		current_screen->update(window);

		// Process events
		sf::Event event;
		while (window.pollEvent(event)){
			// Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::TextEntered) {
				std::cout << "tekst";
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				current_screen->activate_selected();
			}			
		}
	}
	return 0;
}