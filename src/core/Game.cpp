#include "../../include/core/Game.hpp"

Game::Game(std::string title) : Game(title, sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().bitsPerPixel) {}


Game::Game(std::string title, unsigned int windowWidth, unsigned int windowHeight, unsigned int bitsPerPixel)
    : videoMode(windowWidth, windowHeight, bitsPerPixel),
    window(videoMode, title),
    menu(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)) {}
    
Game::~Game() {
    window.close();
}

void Game::start() {

    while(window.isOpen()) {

        sf::Event event;

        while(window.pollEvent(event)) {

            switch (event.type) {
            case sf::Event::Closed:
                stop();
                break;

            default:
                break;
            }

        }

        window.clear();
        menu.draw(window);
        window.display();
    }

}

void Game::stop() {
    window.close();
}

void Game::pause() {

}

void Game::update() {

}

