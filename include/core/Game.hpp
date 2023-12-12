#ifndef CORE_GAME_H
#define CORE_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"

class Game
{
   
public:
    Game(std::string title);
    Game(std::string title, unsigned int windowWidth, unsigned int windowHeight, unsigned int bitsPerPixel); //Should be only use for developement purposes. The game is in fullscreen by default.
    ~Game();
    void start();
    void stop();
    void pause();
    void update();
    void changeMainMenuWindow(int menuIndex);
   
private:
    sf::VideoMode videoMode;
    sf::RenderWindow window;
    Menu mainMenu;

};
#endif