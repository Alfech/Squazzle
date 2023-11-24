#include <iostream>
#include "../include/core/Game.hpp"

int main() {
    
    std::cout << "Hello, World!"  << std::endl;

    Game game = Game("Squazzle", 600, 600, 32);

    game.start();

    return 0;
}