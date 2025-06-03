//
// Created by David Rynearson on 03.06.25.
//

#include "../includes/Enemy.hpp"

Enemy::Enemy(int x, int y, int w, int h) {
    rect = { x, y, w, h};
}

void Enemy::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 180, 0, 0, 255); // Red
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Enemy::getRect() const {
    return rect;
}

