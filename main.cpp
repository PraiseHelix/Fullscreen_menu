#include <iostream>
#include <SFML/Graphics.hpp>
#include "text_option.hpp"
#include <string>
#include "Menu_screen.hpp"

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
	//menu_screen controls_screen(std::string("Controls"), Titlefont, windowwidth, windowheight);
	menu_screen* current_screen = &start_screen;

	//Title screen
	auto newgame = std::make_shared<text_option>("New Game", sf::Vector2f(float(windowwidth / 2), 200), []() {std::cout << "New_game_event";}, 30, Titlefont, sf::Color::Yellow, sf::Color::Blue);
	auto loadgame = std::make_shared<text_option>("Load Game", sf::Vector2f(float(windowwidth / 2), 300), []() {std::cout << "Load_game_event"; }, 30, Titlefont);
	auto settings = std::make_shared<text_option>("Settings", sf::Vector2f(float(windowwidth / 2), 400), [&current_screen, &settings_screen]() {current_screen = &settings_screen; }, 30, Titlefont);
	auto quit = std::make_shared<text_option>("Quit", sf::Vector2f(float(windowwidth / 2), 500), [&window]() {std::cout << "Quit_event"; window.close(); }, 30, Titlefont);

	start_screen.add(newgame);
	start_screen.add(loadgame);
	start_screen.add(settings);
	start_screen.add(quit);
	
	//Settings screen
	auto settings_back = std::make_shared<text_option>("Back", sf::Vector2f(float(windowwidth / 2), 500), [&current_screen, &start_screen]() {current_screen = &start_screen; }, 30, Titlefont);
	auto text_framerate = std::make_shared<text_option>("Framerate Limit	" + std::to_string(frameratelimit), sf::Vector2f(float(windowwidth / 2), 200), []() {}, 30, Titlefont);
	auto controls_option = std::make_shared<text_option>("Controls", sf::Vector2f(float(windowwidth / 2), 400), [&current_screen]() {/*current_screen = &controls_screen;*/ }, 30, Titlefont);

	//de framerate aanpassen lambda
	text_framerate->set_lambda([&]() {
		text_framerate->setString("Framerate Limit	__");

		sf::Event inputevent;
		std::string newframerate;
		while (window.waitEvent(inputevent)) {
			window.clear();
			current_screen->draw(window);
			window.display();

			if (inputevent.type == sf::Event::TextEntered) {
				if (inputevent.text.unicode >= '0' && inputevent.text.unicode <= '9') {
					newframerate += inputevent.text.unicode;
					if (newframerate.size() == 1) {
						text_framerate->setString("Framerate Limit	" + newframerate + "_");
					}
					else {
						text_framerate->setString("Framerate Limit	" + newframerate);
						break;
					}
				}
			}
		}
		frameratelimit = std::stoi(newframerate);
		window.setFramerateLimit(frameratelimit);
	});

	settings_screen.add(settings_back);
	settings_screen.add(text_framerate);
	settings_screen.add(controls_option);

	////Controls Screen
	//text_option left_setting("Left", sf::Vector2f(float(windowwidth / 3), 200), []() {}, 30, Titlefont);
	//text_option right_setting("Right", sf::Vector2f(float(windowwidth / 3), 200), []() {}, 30, Titlefont);
	//text_option up_setting("Up", sf::Vector2f(float(windowwidth / 3), 200), []() {}, 30, Titlefont);
	//text_option down_setting("Down", sf::Vector2f(float(windowwidth / 3), 200), []() {}, 30, Titlefont);

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
				
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				current_screen->activate_selected();
			}		
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					current_screen->scroll_down();
				}
				else if (event.key.code == sf::Keyboard::Down) {
					current_screen->scroll_up();
				}
				else if (event.key.code == sf::Keyboard::Enter) {
					current_screen->activate_selected();
				}
			}
		}
	}
	return 0;
}