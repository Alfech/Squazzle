#include <iostream>
#include "../include/core/Game.hpp"

int main() {
    
    std::cout << "Hello, World!"  << std::endl;

    Game game = Game("Test", 500, 500, 32);

    game.start();

    return 0;
}