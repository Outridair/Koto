//
// Created by David Rynearson on 02.06.25.
//

#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include <memory>

#include "Enemy.hpp"
#include "Tile.hpp"

class Level {
public:
    void init();
    void render(SDL_Renderer* renderer);
    const std::vector<std::unique_ptr<Tile>> & getTiles() const;
    const std::vector<std::unique_ptr<Enemy>>& getEnemies() const;

private:
    std::vector<std::unique_ptr<Tile>> tiles;
    std::vector<std::unique_ptr<Enemy>> enemies;
};



#endif //LEVEL_HPP
