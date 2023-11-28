#ifndef CORE_MENU_H
#define CORE_MENU_H
#include <SFML/Graphics.hpp>

class Menu
{

public:
    Menu();
    Menu(std::vector<std::string> menuElements, float width, float height, std::string fontPath);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem();
    void MouseOver();
    void MouseClicked();

private:
    void loadFont(const std::string &fontPath);

    int selectedItemIdex, sizeOfMenu = 0;
    sf::Font font;
    std::vector<sf::Text> menu;
    
};
#endif