//
// Created by David Rynearson on 04.06.25.
//

#include "../includes/SceneManager.hpp"

void SceneManager::setScene(std::unique_ptr<SceneBase> newScene) {
    currentScene.reset();
    SDL_Log("SceneManager::setScene called");
    currentScene = std::move(newScene);
    SDL_Log("SceneManager::setScene - scene switched");
}

SceneBase* SceneManager::getCurrentScene() const {
    return currentScene.get();
}

void SceneManager::handleEvent(const SDL_Event& e) const {
    if (!currentScene) {
        SDL_Log("SceneManager::handleEvent — currentScene is nullptr!");
        return;
    }
    if (currentScene) currentScene->handleEvent(e);
}

void SceneManager::update(float deltaTime) const {
    if (!currentScene) {
        SDL_Log("SceneManager::update — currentScene is nullptr!");
        return;
    }
    currentScene->update(deltaTime);
}

void SceneManager::render(SDL_Renderer* renderer) const {
    if (!currentScene) {
        SDL_Log("SceneManager::render — currentScene is nullptr!");
        return;
    }
    currentScene->render(renderer);
}
