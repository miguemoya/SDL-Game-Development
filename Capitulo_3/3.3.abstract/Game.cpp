//
//  Game.cpp
//  SDL Game Programming Book
//
//
#include "Game.h"
#include <iostream>

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        int flags = 0;
        if (fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        std::cout << "SDL init success\n";

        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        // if the window creation succeeded create our renderer
        if(m_pWindow != 0)
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // sdl could not initialize
    }

    m_bRunning = true; // everything inited successfully, start the main loop

    if(!TheTextureManager::Instance()->load("../../assets/animate.png", "animate", m_pRenderer))
    {
        return false;
    }


    m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
    m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

    std::cout << "init success\n";


    return true;
}

void Game::render()
{

    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

    // loop through our objects and draw them
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }

    SDL_RenderPresent(m_pRenderer);  // draw to the screen
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}



void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
                break;

            default:
                break;
        }
    }
}

void Game::update()
{
    // loop through and update our objects
     for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }

}

// void Game::draw()
// {
//     for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
//     {
//         m_gameObjects[i]->draw(m_pRenderer);
//     }
// }
