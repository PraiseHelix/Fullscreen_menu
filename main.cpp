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
	menu_screen * current_screen;
	std::shared_ptr<g_settings> settings(new g_settings);

	std::shared_ptr<listener_dummy> listener(new listener_dummy);

	sf::Font font;
	font.loadFromFile("Pokemon Solid.ttf");
	auto tmp_size = window.getSize();

	//menu screens
	menu_screen title_screen(window, "Pocket-Animals", font);
	menu_screen settings_screen(window, "Settings", font);

	//title menu container
	//the title menu options
	std::shared_ptr<generic_option> start_option = std::make_shared<generic_option>("Start", font, sf::Vector2f(float(tmp_size.x / 2), 300), listener);
	std::shared_ptr<generic_option> settings_option = std::make_shared<generic_option>("Settings", font, sf::Vector2f(float(tmp_size.x / 2), 400), listener);
	std::shared_ptr<generic_option> quit_option = std::make_shared<generic_option>("Quit", font, sf::Vector2f(float(tmp_size.x / 2), 500), listener);
	//settings lambda's
	settings_option->set_activation_function([&current_screen, &settings_screen] {current_screen = &settings_screen; });
	//adding to the title menu
	title_screen.push_back(start_option);
	title_screen.push_back(settings_option);
	title_screen.push_back(quit_option);

	

	//settings menu container
	//the settings menu options
	std::shared_ptr<generic_option> framerate_option = std::make_shared<generic_option>("Framerate Limit	", font, sf::Vector2f(float(tmp_size.x / 2), 300), listener);
	std::shared_ptr<generic_option> vsync_option;
	if (settings->vsync) {
		vsync_option = std::make_shared<generic_option>("Vsync	On", font, sf::Vector2f(float(tmp_size.x / 2), 400), listener);
	}
	else {
		vsync_option = std::make_shared<generic_option>("Vsync	Off", font, sf::Vector2f(float(tmp_size.x / 2), 400), listener);
	}
	std::shared_ptr<generic_option> back_option = std::make_shared<generic_option>("Back", font, sf::Vector2f(float(tmp_size.x / 2), 500), listener);
	//settings lambda's
	vsync_option->set_activation_function([&vsync_option, settings] {
		if (settings->vsync) {
			settings->vsync = false;
			vsync_option->setString("Vsync	Off");
		}
		else {
			settings->vsync = true;
			vsync_option->setString("Vsync	On");
		}
	});

	back_option->set_activation_function([&current_screen, &title_screen] {current_screen = &title_screen; });
	//adding to the settings menu
	settings_screen.push_back(framerate_option);
	settings_screen.push_back(vsync_option);
	settings_screen.push_back(back_option);

	current_screen = &title_screen;

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

