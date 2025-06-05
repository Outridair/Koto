//
// Created by David Rynearson on 03.06.25.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "SDL.h"
#include "GameObject.hpp"

class Enemy : public GameObject {
public:
    Enemy(int x, int y, int w, int h);

    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer, const SDL_Rect& camera) override;

    [[nodiscard]] SDL_Rect getRect() const;  // optional, not part of GameObject
private:
    SDL_Rect rect{};
};



#endif //ENEMY_HPP
