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
    void MouseOver(int x, int y);
    int GetMouseClicked(int x, int y);
    int GetPressedItemIndex();
    void changeValueOfMenu(int index, std::string newValue);

private:
    int selectedItemIndex, sizeOfMenu = 0;
    sf::Font font;
    std::vector<sf::Text> menu;
    void loadFont(const std::string &fontPath);
    int getSelectedItemIndex();
    bool isMouseOver(int x, int y, sf::Text text);
};
#endif