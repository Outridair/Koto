//
// Created by David Rynearson on 04.06.25.
//

#include "../includes/Goal.hpp"

Goal::Goal(int x, int y) {
    rect = { x, y, 32, 128};
}

void Goal::render(SDL_Renderer *renderer, const SDL_Rect &camera) {
    SDL_Rect dest = {
        rect.x - camera.x,
        rect.y - camera.y,
        rect.w,
        rect.h
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Yellow pole
    SDL_RenderFillRect(renderer, &dest);
}

SDL_Rect Goal::getRect() const {
    return rect;
}
