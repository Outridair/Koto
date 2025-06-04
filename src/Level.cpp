//
// Created by David Rynearson on 02.06.25.
//

#include "../includes/Level.hpp"
const int tileSize = 40;
const int levelWidth = 3200;
const int tileCount = levelWidth / tileSize;

void Level::init() {
    for (int i = 0; i < tileCount; ++i) {
        tiles.push_back(std::make_unique<Tile>(i * tileSize, 560, tileSize, tileSize));
    }
    // Add one simple enemy
    enemies.push_back(std::make_unique<Enemy>(400, 528, 32, 32));
    goal = std::make_unique<Goal>(3000, 432);
}

void Level::render(SDL_Renderer *renderer, const SDL_Rect& camera) {
    for (const auto& tile : tiles) {
        tile->render(renderer, camera);
    }
    for (const auto& enemy : enemies) {
        enemy->render(renderer, camera);
    }
    if (goal) goal->render(renderer, camera);
}

Goal* Level::getGoal() {
    return goal.get();
}

const std::vector<std::unique_ptr<Tile>>& Level::getTiles() const {
    return tiles;
}
const std::vector<std::unique_ptr<Enemy>>& Level::getEnemies() const {
    return enemies;
}