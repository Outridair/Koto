//
// Created by David Rynearson on 03.06.25.
//

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "SDL.h"

class GameObject {
public:
    virtual void update(float deltaTime) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual ~GameObject() {}
};



#endif //GAMEOBJECT_HPP
