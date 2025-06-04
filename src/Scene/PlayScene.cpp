//
// Created by David Rynearson on 04.06.25.
//

#include "../../includes/Scene/PlayScene.hpp"

PlayScene::PlayScene(SDL_Renderer *renderer): camera(800, 600, 3200, 600) {
    level.init();
    player.init(renderer, 100, 500);
}

void PlayScene::handleEvent(const SDL_Event &e) {
    player.handleInput(e);
}

void PlayScene::update(float deltaTime) {
    player.update(deltaTime, level.getTiles(), level.getEnemies());
    camera.update(player.getX(), player.getY());
}

void PlayScene::render(SDL_Renderer *renderer) {
    SDL_Rect camView = camera.getView();
    level.render(renderer, camView);
    player.render(renderer, camView);
}



