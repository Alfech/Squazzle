#include "../../include/core/Game.hpp"
#include <SFML/Window.hpp>

Game::Game(std::string title){
    //std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();sf::VideoMode::getFullscreenModes();
    
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    Game(title, desktop.width, desktop.height, desktop.bitsPerPixel);
}

Game::Game(std::string title, unsigned int windowWidth, unsigned int windowHeight, unsigned int bitsPerPixel){
    
    videoMode = sf::VideoMode(windowWidth, windowHeight, bitsPerPixel);
    window.create(videoMode, title);
    
}

Game::~Game(){
   window.close();
}

void Game::start(){

    while(window.isOpen()){

        sf::Event event;

        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                this->stop();
            }
        }

    }

}

void Game::stop(){

    this->~Game();
}

void Game::pause(){

}

void Game::update(){

}

