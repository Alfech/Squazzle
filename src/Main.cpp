#include <iostream>
#include "../include/core/Game.hpp"

int main()
{

    std::cout << "Hello! If you see this message, it means that you are in debug mode." << std::endl;

    Game game = Game("Squazzle", 600, 600, 32);

    game.start();

    return 0;
}