//
// Created by David Rynearson on 04.06.25.
//

#include "../../includes/Scene/SceneManager.hpp"

void SceneManager::setScene(std::unique_ptr<Scene> newScene) {
    currentScene = std::move(newScene);
}

Scene* SceneManager::getCurrentScene() {
    return currentScene.get();
}

void SceneManager::handleEvent(const SDL_Event& e) {
    if (!currentScene) {
        SDL_Log("SceneManager::handleEvent — currentScene is nullptr!");
        return;
    }
    if (currentScene) currentScene->handleEvent(e);
}

void SceneManager::update(float deltaTime) {
    if (!currentScene) {
        SDL_Log("SceneManager::update — currentScene is nullptr!");
        return;
    }
    currentScene->update(deltaTime); // 🔥 crashing here if null
}

void SceneManager::render(SDL_Renderer* renderer) {
    if (!currentScene) {
        SDL_Log("SceneManager::render — currentScene is nullptr!");
        return;
    }
    currentScene->render(renderer);
}