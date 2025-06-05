//
// Created by David Rynearson on 04.06.25.
//

#include "../../includes/Scene/Overworld.hpp"
#include "../../includes/Scene/Level.hpp"

Overworld::Overworld(SDL_Renderer* renderer, SceneManager* sceneManager)
    : renderer(renderer), sceneManager(sceneManager) {

    // // Sample 2 levels
    // nodes.push_back({ SDL_Rect{ 200, 300, 100, 50 }, "forest" });
    // nodes.push_back({ SDL_Rect{ 400, 300, 100, 50 }, "cave" });

    SDL_Log("OverworldScene initialized.");
}

void Overworld::handleEvent(const SDL_Event& e) {
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_RIGHT:
                selectedIndex = (selectedIndex + 1) % nodes.size();
                break;
            case SDLK_LEFT:
                selectedIndex = (selectedIndex - 1 + nodes.size()) % nodes.size();
                break;
            case SDLK_RETURN:
                sceneManager->setScene(std::make_unique<Level>(renderer, sceneManager, nodes[selectedIndex].id));
                break;
        }
    }
}

void Overworld::update(float) {
    // Nothing animated yet
}

void Overworld::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255); // Dark green bg
    SDL_RenderClear(renderer);

    for (size_t i = 0; i < nodes.size(); ++i) {
        if (i == selectedIndex) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // yellow for selected
        } else {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
        }
        SDL_RenderFillRect(renderer, &nodes[i].rect);
    }
}