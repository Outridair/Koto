//
// Created by David Rynearson on 04.06.25.
//

#ifndef OVERWORLD_HPP
#define OVERWORLD_HPP

#include "SceneBase.hpp"
#include "../SceneManager.hpp"
#include "SDL.h"
#include <vector>
#include <string>

struct LevelNode {
    SDL_Rect rect;
    int id;
};

class Overworld : public SceneBase {
public:
    Overworld(SDL_Renderer* renderer, SceneManager* sceneManager);
    void handleEvent(const SDL_Event& e) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    ~Overworld() override = default;

private:
    SDL_Renderer* renderer;
    SceneManager* sceneManager;
    std::vector<LevelNode> nodes;
    int selectedIndex = 0;
};



#endif //OVERWORLD_HPP
