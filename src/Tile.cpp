//
// Created by David Rynearson on 02.06.25.
//

#include "../includes/Tile.hpp"

#include "../includes/Tile.hpp"

Tile::Tile(int x, int y, int w, int h) {
    rect = {x, y, w, h};
}

void Tile::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255); // Green
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Tile::getRect() const {
    return rect;
}
