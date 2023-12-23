#ifndef CORE_COREDATA_H
#define CORE_COREDATA_H

#include <iostream>

namespace CoreData
{
    struct Elements
    {
        int index;
        std::string name;
    };

    extern const Elements play;
    extern const Elements options;
    extern const Elements loadImage;
    extern const Elements exit;
    struct MainMenuStruct
    {
        const Elements PLAY = play;
        const Elements OPTIONS = options;
        const Elements LOAD_IMAGE = loadImage;
        const Elements EXIT = exit;
    };
    extern const MainMenuStruct mainMenu;

    extern const Elements backToMenu;
    extern const Elements numberOfTiles;
    struct OptionMenuStruct
    {
        const Elements BACK_TO_MENU = backToMenu;
        const Elements NUMBER_OF_TILES = numberOfTiles;
    };
    extern const OptionMenuStruct optionsMenu;

    extern const Elements easy;
    extern const Elements medium;
    extern const Elements hard;
    struct difficultyStruct
    {
        const Elements EASY = easy;
        const Elements MEDIUM = medium;
        const Elements HARD = hard;
    };
    extern const difficultyStruct difficulty;

}
#endif