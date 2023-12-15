#include "../../include/core/Game.hpp"

Game::Game(std::string title) : Game(title, sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().bitsPerPixel) {}

Game::Game(std::string title, unsigned int windowWidth, unsigned int windowHeight, unsigned int bitsPerPixel)
    : videoMode(windowWidth, windowHeight, bitsPerPixel),
      window(videoMode, title),
      mainMenu(std::vector<std::string>({"Play", "Options", "Load Images", "Exit"}), static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y), "./src/resources/fonts/GROBOLD.ttf") {}

Game::~Game()
{
    window.close();
}

void Game::start()
{
    int mainMenuIndex = -1;

    while (window.isOpen())
    {
        switch (mainMenuIndex)
        {
        case 0:
            std::cout << "Play" << std::endl;
            break;

        case 1:
            std::cout << "Options" << std::endl;
            break;

        case 2:
        {
            if (openFile())
            {
            }
            else
            {
                mainMenuIndex = -1;
            }

            break;
        }

        case 3:
            stop();
            break;

        default:
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
                        break;

                    case sf::Keyboard::Down:
                        mainMenu.MoveDown();
                        break;

                    case sf::Keyboard::Return:
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

                default:
                    break;
                }
            }

            window.clear();
            mainMenu.draw(window);
            window.display();
            break;
        }
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
bool Game::openFile()
{
    std::string sSelectedFile;
    std::string sFilePath;

    bool succeeded = FALSE;

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
            char path[MAX_PATH];
            DWORD length = GetModuleFileName(NULL, path, MAX_PATH);
            PathRemoveFileSpec(path);
            WCHAR* wpath = new WCHAR[length+7];
            MultiByteToWideChar(CP_UTF8, 0, path, -1, wpath, length+7);
            wcscat(wpath, L"\\media");

            IShellItem *pFolderItem;
            f_SysHr = SHCreateItemFromParsingName(wpath, NULL, IID_IShellItem, reinterpret_cast<void **>(&pFolderItem));
            if (SUCCEEDED(f_SysHr))
            {
                f_SysHr = f_FileSystem->SetFolder(pFolderItem);
                pFolderItem->Release();
            }

            //  SHOW OPEN FILE DIALOG WINDOW
            f_SysHr = f_FileSystem->Show(NULL);
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

                        //  FORMAT STRING FOR EXECUTABLE NAME
                        const size_t slash = sFilePath.find_last_of("/\\");
                        sSelectedFile = sFilePath.substr(slash + 1);
                        succeeded = TRUE;
                    }
                    f_Files->Release();
                }
            }
            f_FileSystem->Release();
        }
        CoUninitialize();
    }
    return succeeded;
}
