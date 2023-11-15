#include <iostream>
#include "../include/core/Game.hpp"

int main() {
    
    std::cout << "Hello, World!"  << std::endl;

    Game game = Game("Test");

    game.start();

    return 0;
}