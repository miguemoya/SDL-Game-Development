#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "TextureManager.h"
#ifndef __Game__
#define __Game__

class Game
{
    public:

        Game() {}
        ~Game() {}


        bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);

        void render();
        void update();
        void handleEvents();
        void clean();
        bool running() {return m_bRunning;};



    private:

        SDL_Window* m_pWindow = 0;
        SDL_Renderer* m_pRenderer = 0;

        SDL_Texture* m_pTexture; // the new SDL_Texture variable

        int m_currentFrame;

        bool m_bRunning;
};

#endif /* defined(__Game__) */
