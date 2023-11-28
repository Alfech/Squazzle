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

    while (window.isOpen())
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

                    switch(mainMenu.GetPressedItem())
                    {
                        case 0:
                            std::cout << "Play" << std::endl;
                            break;
                        
                        case 1:
                            std::cout << "Options" << std::endl;
                            break;

                        case 2:
                            std::cout << "Load images" << std::endl;
                            break;

                        case 3:
                            std::cout << "Exit" << std::endl;
                            break;
                    }
                    break;
                
                default:
                    break;

                }
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
