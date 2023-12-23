#include "../../include/core/Game.hpp"

Game::Game(std::string title) : Game(title, sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().bitsPerPixel) {}

Game::Game(std::string title, unsigned int windowWidth, unsigned int windowHeight, unsigned int bitsPerPixel)
    : videoMode(windowWidth, windowHeight, bitsPerPixel),
      window(videoMode, title),
      mainMenu(std::vector<std::string>({CoreData::mainMenu.PLAY.name, CoreData::mainMenu.OPTIONS.name, CoreData::mainMenu.LOAD_IMAGE.name, CoreData::mainMenu.EXIT.name}), static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y), "./src/resources/fonts/GROBOLD.ttf"),
      option(std::vector<std::string>({CoreData::optionsMenu.BACK_TO_MENU.name, CoreData::optionsMenu.NUMBER_OF_TILES.name + " " + CoreData::difficulty.EASY.name}), static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y), "./src/resources/fonts/GROBOLD.ttf")

{
    // Force the window to be maximize.
    HWND hwnd = window.getSystemHandle();
    ShowWindow(hwnd, SW_MAXIMIZE);
}

Game::~Game()
{
    window.close();
}

void Game::start()
{
    int mainMenuIndex = -1;
    int currentDifficulty = CoreData::difficulty.EASY.index;

    while (window.isOpen())
    {

        if (mainMenuIndex == CoreData::mainMenu.PLAY.index)
        {
            std::cout << "Play" << std::endl;
            mainMenuIndex = -1;
        }
        else if (mainMenuIndex == CoreData::mainMenu.OPTIONS.index)
        {
            int optionIndex = -1;
            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        option.MoveUp();
                        break;

                    case sf::Keyboard::Down:
                        option.MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        optionIndex = option.GetPressedItemIndex();
                        break;

                    default:
                        break;
                    }
                    break;

                case sf::Event::MouseMoved:
                    option.MouseOver(event.mouseMove.x, event.mouseMove.y);
                    break;

                case sf::Event::MouseButtonReleased:
                    optionIndex = option.GetMouseClicked(event.mouseButton.x, event.mouseButton.y);
                    break;

                case sf::Event::Closed:
                    stop();
                    break;

                case sf::Event::Resized:
                {
                    sf::FloatRect visibleArea = sf::FloatRect(0.f, 0.f, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));
                    option.updateMenuPosition(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
                    break;
                }

                default:
                    break;
                }
            }

            if (optionIndex == CoreData::optionsMenu.BACK_TO_MENU.index)
            {
                mainMenuIndex = -1;
            }
            else if (optionIndex == CoreData::optionsMenu.NUMBER_OF_TILES.index)
            {
                currentDifficulty = (currentDifficulty + 1) % 3;
                std::cout << "Difficulty : " << currentDifficulty << std::endl;

                if (currentDifficulty == CoreData::difficulty.EASY.index)
                {
                    option.changeValueOfMenu(CoreData::optionsMenu.NUMBER_OF_TILES.index, CoreData::optionsMenu.NUMBER_OF_TILES.name + " " + CoreData::difficulty.EASY.name);
                }
                else if (currentDifficulty == CoreData::difficulty.MEDIUM.index)
                {
                    option.changeValueOfMenu(CoreData::optionsMenu.NUMBER_OF_TILES.index, CoreData::optionsMenu.NUMBER_OF_TILES.name + " " + CoreData::difficulty.MEDIUM.name);
                }
                else if (currentDifficulty == CoreData::difficulty.HARD.index)
                {
                    option.changeValueOfMenu(CoreData::optionsMenu.NUMBER_OF_TILES.index, CoreData::optionsMenu.NUMBER_OF_TILES.name + " " + CoreData::difficulty.HARD.name);
                }
            }

            window.clear();
            option.draw(window);
            window.display();
        }
        else if (mainMenuIndex == CoreData::mainMenu.LOAD_IMAGE.index)
        {
            std::string imagePath = openFile();

            if (imagePath.empty())
            {
                mainMenu.changeValueOfMenu(2, "Load Images");
            }
            else
            {
                std::cout << imagePath << std::endl;
                const size_t slash = imagePath.find_last_of("/\\");
                std::string imageName = imagePath.substr(slash + 1);
                mainMenu.changeValueOfMenu(2, "Load Images - " + imageName);
            }

            mainMenuIndex = -1;
        }
        else if (mainMenuIndex == CoreData::mainMenu.EXIT.index)
        {
            stop();
        }
        else
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        mainMenu.MoveUp();
                        std::cout << "Up : " << mainMenu.GetPressedItemIndex() << std::endl;
                        break;

                    case sf::Keyboard::Down:
                        mainMenu.MoveDown();
                        std::cout << "Down : " << mainMenu.GetPressedItemIndex() << std::endl;
                        break;

                    case sf::Keyboard::Return:
                        std::cout << "Enter : " << mainMenu.GetPressedItemIndex() << std::endl;
                        mainMenuIndex = mainMenu.GetPressedItemIndex();
                        break;

                    default:
                        break;
                    }
                    break;

                case sf::Event::MouseMoved:
                    mainMenu.MouseOver(event.mouseMove.x, event.mouseMove.y);
                    break;

                case sf::Event::MouseButtonReleased:
                    mainMenuIndex = mainMenu.GetMouseClicked(event.mouseButton.x, event.mouseButton.y);
                    break;

                case sf::Event::Closed:
                    stop();
                    break;

                case sf::Event::Resized:
                {
                    sf::FloatRect visibleArea = sf::FloatRect(0.f, 0.f, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));
                    mainMenu.updateMenuPosition(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
                    break;
                }

                default:
                    break;
                }
            }
            window.clear();
            mainMenu.draw(window);
            window.display();
        }
    }
}

void Game::stop()
{
    window.close();
}

void Game::pause()
{
}

void Game::update()
{
}

// https://stackoverflow.com/questions/68601080/how-do-you-open-a-file-explorer-dialogue-in-c
std::string Game::openFile()
{
    std::string sFilePath = "";

    //  CREATE FILE OBJECT INSTANCE
    HRESULT f_SysHr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (SUCCEEDED(f_SysHr))
    {
        // CREATE FileOpenDialog OBJECT
        IFileOpenDialog *f_FileSystem;
        f_SysHr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void **>(&f_FileSystem));
        if (SUCCEEDED(f_SysHr))
        {

            // SET INITIAL FOLDER
            WCHAR path[MAX_PATH];
            DWORD length = GetModuleFileName(NULL, path, MAX_PATH);
            PathRemoveFileSpec(path);
            wcscat(path, L"\\media");

            IShellItem *pFolderItem;
            f_SysHr = SHCreateItemFromParsingName(path, NULL, IID_IShellItem, reinterpret_cast<void **>(&pFolderItem));
            if (SUCCEEDED(f_SysHr))
            {
                f_SysHr = f_FileSystem->SetFolder(pFolderItem);
                pFolderItem->Release();
            }

            //  SHOW OPEN FILE DIALOG WINDOW
            HWND hwnd = window.getSystemHandle();
            f_SysHr = f_FileSystem->Show(hwnd);
            if (SUCCEEDED(f_SysHr))
            {
                //  RETRIEVE FILE NAME FROM THE SELECTED ITEM
                IShellItem *f_Files;
                f_SysHr = f_FileSystem->GetResult(&f_Files);
                if (SUCCEEDED(f_SysHr))
                {
                    //  STORE AND CONVERT THE FILE NAME
                    PWSTR f_Path;
                    f_SysHr = f_Files->GetDisplayName(SIGDN_FILESYSPATH, &f_Path);
                    if (SUCCEEDED(f_SysHr))
                    {
                        //  FORMAT AND STORE THE FILE PATH
                        std::wstring path(f_Path);
                        std::string c(path.begin(), path.end());
                        sFilePath = c;
                    }
                    f_Files->Release();
                }
            }
            f_FileSystem->Release();
        }
        CoUninitialize();
    }
    return sFilePath;
}
