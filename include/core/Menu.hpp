#ifndef CORE_MENU_H
#define CORE_MENU_H
#include <SFML/Graphics.hpp>


#define MENU_ITEM_SIZE 4
class Menu
{

enum MenuItem {
    Play,
    Options,
    LoadImages,
    Exit,
};

public:
    Menu();
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();

private:
    void loadFont(const std::string &fontPath);

    int selectedItemIdex;
    sf::Font font;
    sf::Text menu[MENU_ITEM_SIZE];
    

};
#endif