#ifndef __GameObject__
#define __GameObject__

#include<SDL2/SDL.h>
#include <string>

class GameObject
{

public:
    // función virtual: es una función miembro que se espera volver a definir en las clases derivadas.
    /*
     * Cuando se hace referencia a un objeto de clase derivada mediante un puntero o una referencia a la clase base,
     * se puede llamar a una función virtual para ese objeto y ejecutar la versión de la clase derivada de la función.
    */
    virtual void load(int x, int y, int width, int height, std::string textureID);
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void update();
    virtual void clean();

protected:

    std::string m_textureID;

    int m_currentFrame;
    int m_currentRow;

    int m_x;
    int m_y;

    int m_width;
    int m_height;

};


#endif
