//
// Created by David Rynearson on 04.06.25.
//

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include "Scene.hpp"
#include <memory>

class SceneManager {
public:
    SceneManager() = default;

    void setScene(std::unique_ptr<Scene> newScene);
    Scene* getCurrentScene();

    void handleEvent(const SDL_Event& e);
    void update(float deltaTime);
    void render(SDL_Renderer* renderer);

private:
    std::unique_ptr<Scene> currentScene;
};



#endif //SCENEMANAGER_HPP
