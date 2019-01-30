#include <iostream>
#include <SFML/Graphics.hpp>
#include "generic_option.hpp"
#include "option_listener.hpp"
#include "menu_screen.hpp"
#include "listener_dummy.hpp"
#include "Title_screen.hpp"
#include "settings.hpp"


int main(){
	const int windowwidth = 800;
	const int windowheight = 600;
	const int frameratelimit = 60;

	sf::RenderWindow window(sf::VideoMode(windowwidth, windowheight), "Main_Window");
	window.setFramerateLimit(frameratelimit);

	std::shared_ptr<g_settings> settings(new g_settings);
	//auto settings = std::make_shared<g_settings>;

	std::shared_ptr<listener_dummy> listener(new listener_dummy);
	//listener_dummy listener;

	title_screen title(window,listener);

	settings_screen settings_screen(window, listener, settings);

	menu_screen * current_screen = &settings_screen;

	while (window.isOpen()) {

		window.clear();

		current_screen->on_update();
		current_screen->on_draw();

		window.display();

		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				current_screen->on_activate();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					current_screen->scroll_up();
				}
				else if (event.key.code == sf::Keyboard::Down) {
					current_screen->scroll_down();
				}
				else if (event.key.code == sf::Keyboard::Return) {
					current_screen->on_activate();
				}
			}
		}
	}

	return 0;
}

