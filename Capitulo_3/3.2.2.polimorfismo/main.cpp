#include "Game.h"

Game *g_game = 0;

int main (int argc, char *argv[])
{
    (void) argc;    // para evitar warnings: unused parameter ‘argc’ [-Wunused-parameter]
    (void) argv;

    g_game = new Game();

    g_game->init("Chapter 3", 100, 100, 640, 480, false);

    while(g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();

        SDL_Delay(10); // add the delay
    }
    g_game->clean();

    return 0;
}



