//#pragma once
//#include <SFML/Graphics.hpp>
//#include "menu_screen.hpp"
//#include "generic_option.hpp"
//#include "settings.hpp"
//
//class title_screen :public menu_screen {
//public:
//	title_screen(sf::RenderWindow & window, std::shared_ptr<option_listener> listener): menu_screen(window) {
//		font.loadFromFile("Pokemon Solid.ttf");
//		auto tmp_size = window.getSize();
//
//		//Title text
//		title.setString("Pocket-Animals");
//		title.setFont(font);
//		title.setOrigin((title.getGlobalBounds().width/2)+title.getGlobalBounds().left, (title.getGlobalBounds().height / 2) + title.getGlobalBounds().top );
//		title.setPosition(float(tmp_size.x/2), 100);
//		title.setFillColor(sf::Color::Green);
//
//		//the menu options
//		auto start_option = std::make_shared<generic_option>("Start", font, sf::Vector2f(float(tmp_size.x / 2), 300), listener);
//		auto settings_option = std::make_shared<generic_option>("Settings", font, sf::Vector2f(float(tmp_size.x / 2), 400), listener);
//		auto quit_option = std::make_shared<generic_option>("Quit", font, sf::Vector2f(float(tmp_size.x / 2), 500), listener);
//
//		//adding to the menu
//		options.push_back(start_option);
//		options.push_back(settings_option);
//		options.push_back(quit_option);
//	}
//};
//
//
//class settings_screen : public menu_screen {
//public:
//	std::shared_ptr<g_settings> settings;
//
//	settings_screen(sf::RenderWindow & window, std::shared_ptr<option_listener> listener, std::shared_ptr<g_settings> settings) : menu_screen(window), settings(settings) {
//		font.loadFromFile("Pokemon Solid.ttf");
//		auto tmp_size = window.getSize();
//
//		//Title text
//		title.setString("Settings");
//		title.setFont(font);
//		title.setOrigin((title.getGlobalBounds().width / 2) + title.getGlobalBounds().left, (title.getGlobalBounds().height / 2) + title.getGlobalBounds().top);
//		title.setPosition(float(tmp_size.x / 2), 100);
//		title.setFillColor(sf::Color::Green);
//
//		//the menu options
//		auto framerate_option = std::make_shared<generic_option>("Framerate Limit	", font, sf::Vector2f(float(tmp_size.x / 2), 300), listener);
//		auto vsync_option = std::make_shared<generic_option>("Vsync	" + std::to_string(settings->vsync), font, sf::Vector2f(float(tmp_size.x / 2), 400), listener);
//		auto back_option = std::make_shared<generic_option>("Back", font, sf::Vector2f(float(tmp_size.x / 2), 500), listener);
//
//		vsync_option->set_activation_function([vsync_option, settings] {
//			if (settings->vsync) {
//				settings->vsync = false;
//			}
//			else {
//				settings->vsync = true;
//			}
//			vsync_option->setString("Vsync	" + std::to_string(settings->vsync));
//		});
//
//		//adding to the menu
//		options.push_back(framerate_option);
//		options.push_back(vsync_option);
//		options.push_back(back_option);
//	}
//};