#include "../../include/core/CoreData.hpp"

namespace CoreData {

    const Elements play = {.index = 0, .name = "Play"};
    const Elements options = {.index = 1, .name = "Options"};
    const Elements loadImage = {.index = 2, .name = "Load Image"};
    const Elements exit = {.index = 3, .name = "Exit"};

    const MainMenuStruct mainMenu;

    const Elements backToMenu = {.index = 0, .name = "Back to main menu"};
    const Elements numberOfTiles = {.index = 1, .name = "Number of tiles"};

    const OptionMenuStruct optionsMenu;

    const Elements easy = {.index = 0, .name = "(10) 50 100"};
    const Elements medium = {.index = 1, .name = "10 (50) 100"};
    const Elements hard = {.index = 2, .name = "10 50 (100)"};

    const difficultyStruct difficulty;

}