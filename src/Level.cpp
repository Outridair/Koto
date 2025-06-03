//
// Created by David Rynearson on 02.06.25.
//

#include "../includes/Level.hpp"

void Level::init() {
    for (int i = 0; i < 800; i += 40) {
        tiles.push_back(std::make_unique<Tile>(i, 560, 40, 40));
    }
}

void Level::render(SDL_Renderer *renderer) {
    for (const auto& tile : tiles) tile->render(renderer);
}

const std::vector<std::unique_ptr<Tile>>& Level::getTiles() const {
    return tiles;
}