//
//  Game.cpp
//  SDL Game Programming Book
//
//
#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        // if succeeded create our window
        int flags = 0;
        if (fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);


        // if the window creation succeeded create our renderer
        if(m_pWindow != 0)
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer,
                255,255,255,255);
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // sdl could not initialize
    }
    //SDL_Surface* pTempSurface = SDL_LoadBMP("../../assets/animate.bmp");
    //SDL_Surface* pTempSurface = SDL_LoadBMP("../../assets/rider.bmp");
    //SDL_Surface* pTempSurface = IMG_Load("../../assets/animate.png");
    //SDL_Surface* pTempSurface = IMG_Load("../../assets/animate-alpha.png");
    m_textureManager.load("../../assets/animate-alpha.png","animate", m_pRenderer);


    //m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    //SDL_FreeSurface(pTempSurface);

    //SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

    // m_sourceRectangle.w = 128;
    // m_sourceRectangle.h = 82;
    //
    // m_destinationRectangle.x = m_sourceRectangle.x = 0;
    // m_destinationRectangle.y = m_sourceRectangle.y = 0;
    // m_destinationRectangle.w = m_sourceRectangle.w;
    // m_destinationRectangle.h = m_sourceRectangle.h;


    std::cout << "init success\n";
    m_bRunning = true; // everything inited successfully, start the main loop

    return true;
}

void Game::render()
{


    //SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255); //## provisional para poner toda la ventana de color negro
    SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255); //## provisional para poner toda la ventana de color rojo

    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

    m_textureManager.draw("animate", 0,0, 128, 82, m_pRenderer);

    m_textureManager.drawFrame("animate", 100,100, 128, 82, 1, m_currentFrame, m_pRenderer);

    SDL_RenderPresent(m_pRenderer);  // draw to the screen
}

void Game::update()
{
    /* SDL_GetTicks obtiene la cantidad total de milisegundos desde que SDL fue inicializado
       A continuación, lo dividimos por la cantidad de tiempo (en ms) que queremos entre fotogramas y
       después usamos el operador modulo para mantenerlo en el rango de la cantidad de fotogramas que tenemos
       en nuestra animación. (en este caso 5 fotogramas de 128 píxeles de ancho).
    */
    //m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
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

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

