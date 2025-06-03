//
// Created by David Rynearson on 02.06.25.
//

#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include <memory>
#include "Tile.hpp"

class Level {
public:
    void init();
    void render(SDL_Renderer* renderer);
    const std::vector<std::unique_ptr<Tile>> & getTiles() const;

private:
    std::vector<std::unique_ptr<Tile>> tiles;
};



#endif //LEVEL_HPP
