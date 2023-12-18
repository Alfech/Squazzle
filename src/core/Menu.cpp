#include "../../include/core/Menu.hpp"
#include <iostream>
#include <filesystem>

Menu::Menu() {}

Menu::Menu(std::vector<std::string> menuElements, float width, float height, std::string fontPath)
{

    try
    {
        loadFont(fontPath);
    }
    catch (const std::exception &e)
    {
        std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
        std::cerr << "Error : " << e.what() << std::endl;
    }

    sizeOfMenu = menuElements.size();

    for (int i = 0; i < sizeOfMenu; i++)
    {
        menu.emplace_back(menuElements.at(i), font);
        (i == 0) ? menu.at(i).setFillColor(sf::Color::Red) : menu.at(i).setFillColor(sf::Color::White);
        menu.at(i).setPosition(sf::Vector2f(width / 2, height / (sizeOfMenu + 1) * (i + 1)));
        menu[i].setOrigin(menu[i].getGlobalBounds().width / 2, menu[i].getGlobalBounds().height / 2);
    }

    selectedItemIndex = 0;
}

Menu::~Menu() {}

void Menu::draw(sf::RenderWindow &window)
{
    for (const auto &menuItem : menu)
    {
        window.draw(menuItem);
    }
}

void Menu::updateMenuPosition(float width, float height)
{

    for (int i = 0; i < sizeOfMenu; i++)
    {
        menu[i].setPosition(sf::Vector2f(width / 2, height / (sizeOfMenu + 1) * (i + 1)));
    }
}

void Menu::MoveUp()
{
    menu[selectedItemIndex].setFillColor(sf::Color::White);
    (selectedItemIndex == 0) ? selectedItemIndex = sizeOfMenu - 1 : selectedItemIndex -= 1;
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
}

void Menu::MoveDown()
{
    menu[selectedItemIndex].setFillColor(sf::Color::White);
    (selectedItemIndex == sizeOfMenu - 1) ? selectedItemIndex = 0 : selectedItemIndex += 1;
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
}

void Menu::MouseOver(int x, int y)
{
    for (int i = 0; i < sizeOfMenu; i++)
    {
        if (isMouseOver(x, y, menu.at(i)))
        {
            menu[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex = i;
            menu[i].setFillColor(sf::Color::Red);
        }
    }
}

int Menu::GetMouseClicked(int x, int y)
{
    for (const sf::Text &menuItem : menu)
    {
        if (isMouseOver(x, y, menuItem))
        {
            return getSelectedItemIndex();
        }
    }

    return -1;
}

int Menu::GetPressedItemIndex()
{
    return getSelectedItemIndex();
}

void Menu::changeValueOfMenu(int index, std::string newValue)
{
    if (index >= 0 || index < menu.size())
        menu.at(index).setString(newValue);
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

int Menu::getSelectedItemIndex()
{
    return selectedItemIndex;
}

bool Menu::isMouseOver(int x, int y, sf::Text text)
{
    sf::FloatRect textBound = text.getGlobalBounds();
    return textBound.contains(static_cast<float>(x), static_cast<float>(y));
}