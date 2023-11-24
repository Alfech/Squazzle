#include "../../include/core/Menu.hpp"
#include <iostream>
#include <filesystem>

Menu::Menu(){}

Menu::Menu(float width, float height) {

    try {
        loadFont("./src/resources/fonts/GROBOLD.ttf");
    } catch (const std::exception &e) {
        std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
        std::cerr << "Error : " << e.what() << std::endl;
    }

    menu[Play].setFont(font);
    menu[Play].setFillColor(sf::Color::Red);
    menu[Play].setString("Play");
    menu[Play].setPosition(sf::Vector2f(width / 2, height / (MENU_ITEM_SIZE + 1) * 1));

    menu[Options].setFont(font);
    menu[Options].setFillColor(sf::Color::White);
    menu[Options].setString("Options");
    menu[Options].setPosition(sf::Vector2f(width / 2, height / (MENU_ITEM_SIZE + 1) * 2));

    menu[LoadImage].setFont(font);
    menu[LoadImage].setFillColor(sf::Color::White);
    menu[LoadImage].setString("Load Image");
    menu[LoadImage].setPosition(sf::Vector2f(width / 2, height / (MENU_ITEM_SIZE + 1) * 3));

    menu[Exit].setFont(font);
    menu[Exit].setFillColor(sf::Color::White);
    menu[Exit].setString("Exit");
    menu[Exit].setPosition(sf::Vector2f(width / 2, height / (MENU_ITEM_SIZE + 1) * 4));


}

Menu::~Menu() {}

void Menu::draw(sf::RenderWindow &window) {
    for(const sf::Text &menuItem : menu) {
        window.draw(menuItem);
    }
}

void Menu::loadFont(const std::string &fontPath) {

    if(std::filesystem::exists( std::filesystem::path(fontPath) )) {

        if(!font.loadFromFile(fontPath)) {
            throw std::runtime_error("Font file '" + fontPath + "' not found or failed to load.");
        }

    } else {

        throw std::runtime_error("File '" + fontPath + "' does not exists");

    }

}