#include <iostream>
#include <SFML/Window.hpp>

int main() {
    
    std::cout << "Hello, World!"  << std::endl;

    sf::Window window;
    window.create(sf::VideoMode(800, 600), "My Window");

    while(window.isOpen()){

        sf::Event event;

        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
    }

    return 0;
}