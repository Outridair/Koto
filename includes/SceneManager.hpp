//
// Created by David Rynearson on 04.06.25.
//

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include "Scene/SceneBase.hpp"
#include <memory>

class SceneManager {
public:
    SceneManager() = default;

    void setScene(std::unique_ptr<SceneBase> newScene);
    [[nodiscard]] SceneBase* getCurrentScene() const;

    void handleEvent(const SDL_Event& e) const;
    void update(float deltaTime) const;
    void render(SDL_Renderer* renderer) const;

private:
    std::unique_ptr<SceneBase> currentScene;
};



#endif //SCENEMANAGER_HPP
