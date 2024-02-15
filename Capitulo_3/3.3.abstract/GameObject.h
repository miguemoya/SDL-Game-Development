#ifndef __GameObject__
#define __GameObject__

#include "LoaderParams.h"

class GameObject
{

public:

    // abstract base class
    // An abstract base class is a class that contains at least one pure virtual function.
    // A pure virtual function is a function that has no definition and must be implemented in
    // any derived classes. We can make a function pure virtual by suffixing it with =0.
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;

protected:

    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}

};


#endif
