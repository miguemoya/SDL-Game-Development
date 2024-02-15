
#ifndef __Game__
#define __Game__

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"
#include <vector>
#include <iostream>


class Game
{
    public:

        //Game() {}
        //~Game() {}

        // create the public instance function
        static Game* Instance()
        {
            if(s_pInstance == 0)
            {
                s_pInstance = new Game();
                return s_pInstance;
            }
            return s_pInstance;
        }

        bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        //void draw();
        void render();
        void update();
        void handleEvents();
        void clean();
        bool running() {return m_bRunning;};
        SDL_Renderer* getRenderer() const { return m_pRenderer; }


    private:

        Game() {};  // si no inicializaba con {} me fallaba el linker con:
                    //   main.cpp:(.text._ZN4Game8InstanceEv[_ZN4Game8InstanceEv]+0x30): referencia a `Game::Game()' sin definir
        // create the s_pInstance member variable
        static Game* s_pInstance;

        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;

        SDL_Texture* m_pTexture; // the new SDL_Texture variable

        int m_currentFrame;

        bool m_bRunning;

        std::vector<GameObject*> m_gameObjects;

};

// create the typedef
typedef Game TheGame;

#endif /* defined(__Game__) */
