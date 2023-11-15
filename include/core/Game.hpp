#ifndef CORE_GAME_H
#define CORE_GAME_H

#include <SFML/Window.hpp>

class Game
{
   
    public:
        Game(std::string title);
        Game(std::string title, unsigned int windowWidth, unsigned int windowHeight, unsigned int bitsPerPixel); //Only use for developement purposes. The game is in fullscreen by default.
        ~Game();
        void start();
        void stop();
        void pause();
        void update();
   
    private:
        sf::Window window;
        sf::Event event;
        sf::VideoMode videoMode;




};

#endif