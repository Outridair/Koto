//
// Created by David Rynearson on 02.06.25.
//

#include "../includes/Level.hpp"

void Level::init() {
    for (int i = 0; i < 800; i += 40) {
        tiles.push_back(std::make_unique<Tile>(i, 560, 40, 40));
    }
    // Add one simple enemy
    enemies.push_back(std::make_unique<Enemy>(400, 528, 32, 32));
}

void Level::render(SDL_Renderer *renderer) {
    for (const auto& tile : tiles) tile->render(renderer);
    for (const auto& enemy : enemies) enemy->render(renderer);
}

const std::vector<std::unique_ptr<Tile>>& Level::getTiles() const {
    return tiles;
}
const std::vector<std::unique_ptr<Enemy>>& Level::getEnemies() const {
    return enemies;
}