//
// Created by David Rynearson on 03.06.25.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "SDL.h"
#include "GameObject.hpp"

class Enemy: public GameObject {
public:
    Enemy(int x, int y, int w= 32, int h= 32);
    void update(float deltaTime) override {};
    void render(SDL_Renderer* renderer) override;
    SDL_Rect getRect() const;

private:
    SDL_Rect rect;
};



#endif //ENEMY_HPP
