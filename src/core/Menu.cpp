#include "../../include/core/Menu.hpp"
#include <iostream>
#include <filesystem>

Menu::Menu() {}

Menu::Menu(std::vector<std::string> menuElements, float width, float height)
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

    sizeOfMenu = menuElements.size();

    for(int i = 0; i < sizeOfMenu; i++)
    {
        menu.emplace_back(menuElements.at(i), font);
        (i == 0) ? menu.at(i).setFillColor(sf::Color::Red) : menu.at(i).setFillColor(sf::Color::White);
        menu.at(i).setPosition(sf::Vector2f(width / 2, height / (sizeOfMenu + 1) * (i+1)));
    }

    selectedItemIdex = 0;
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
    menu[selectedItemIdex].setFillColor(sf::Color::White);
    (selectedItemIdex == 0) ? selectedItemIdex = sizeOfMenu - 1 : selectedItemIdex -= 1;
    menu[selectedItemIdex].setFillColor(sf::Color::Red);
}

void Menu::MoveDown()
{
    menu[selectedItemIdex].setFillColor(sf::Color::White);
    (selectedItemIdex == sizeOfMenu - 1) ? selectedItemIdex = 0 : selectedItemIdex += 1;
    menu[selectedItemIdex].setFillColor(sf::Color::Red);
}

int Menu::GetPressedItem()
{
    return selectedItemIdex;
}