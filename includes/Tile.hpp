//
// Created by David Rynearson on 02.06.25.
//

#ifndef TILE_HPP
#define TILE_HPP

#include "SDL.h"

class Tile {
public:
    Tile(int x, int y, int w, int h);
    void render(SDL_Renderer* renderer);
    [[nodiscard]] SDL_Rect getRect() const;

private:
    SDL_Rect rect;
};



#endif //TILE_HPP
