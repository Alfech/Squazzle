#include "../../include/core/Menu.hpp"
#include <iostream>
#include <filesystem>

Menu::Menu() {}

Menu::Menu(float width, float height)
{

    try
    {
        loadFont("./src/resources/fonts/GROBOLD.ttf");
    }
    catch (const std::exception &e)
    {
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

    menu[LoadImages].setFont(font);
    menu[LoadImages].setFillColor(sf::Color::White);
    menu[LoadImages].setString("Load Images");
    menu[LoadImages].setPosition(sf::Vector2f(width / 2, height / (MENU_ITEM_SIZE + 1) * 3));

    menu[Exit].setFont(font);
    menu[Exit].setFillColor(sf::Color::White);
    menu[Exit].setString("Exit");
    menu[Exit].setPosition(sf::Vector2f(width / 2, height / (MENU_ITEM_SIZE + 1) * 4));

    selectedItemIdex = Play;
}

Menu::~Menu() {}

void Menu::draw(sf::RenderWindow &window)
{
    for (const sf::Text &menuItem : menu)
    {
        window.draw(menuItem);
    }
}

void Menu::loadFont(const std::string &fontPath)
{

    if (std::filesystem::exists(std::filesystem::path(fontPath)))
    {

        if (!font.loadFromFile(fontPath))
        {
            throw std::runtime_error("Font file '" + fontPath + "' not found or failed to load.");
        }
    }
    else
    {

        throw std::runtime_error("File '" + fontPath + "' does not exists");
    }
}

void Menu::MoveUp()
{

    switch (selectedItemIdex)
    {

    case Play:
        menu[Play].setFillColor(sf::Color::White);
        menu[Exit].setFillColor(sf::Color::Red);
        selectedItemIdex = Exit;
        break;

    case Options:
        menu[Options].setFillColor(sf::Color::White);
        menu[Play].setFillColor(sf::Color::Red);
        selectedItemIdex = Play;
        break;

    case LoadImages:
        menu[LoadImages].setFillColor(sf::Color::White);
        menu[Options].setFillColor(sf::Color::Red);
        selectedItemIdex = Options;
        break;

    case Exit:
        menu[Exit].setFillColor(sf::Color::White);
        menu[LoadImages].setFillColor(sf::Color::Red);
        selectedItemIdex = LoadImages;
        break;
    }
}

void Menu::MoveDown()
{

    switch (selectedItemIdex)
    {

    case Play:
        menu[Play].setFillColor(sf::Color::White);
        menu[Options].setFillColor(sf::Color::Red);
        selectedItemIdex = Options;
        break;

    case Options:
        menu[Options].setFillColor(sf::Color::White);
        menu[LoadImages].setFillColor(sf::Color::Red);
        selectedItemIdex = LoadImages;
        break;

    case LoadImages:
        menu[LoadImages].setFillColor(sf::Color::White);
        menu[Exit].setFillColor(sf::Color::Red);
        selectedItemIdex = Exit;
        break;

    case Exit:
        menu[Exit].setFillColor(sf::Color::White);
        menu[Play].setFillColor(sf::Color::Red);
        selectedItemIdex = Play;
        break;
    }
}