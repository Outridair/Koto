//
// Created by David Rynearson on 04.06.25.
//

#include "../../includes/Scene/StartScene.hpp"

StartScene::StartScene(SDL_Renderer* renderer, SceneManager* sceneManager)
    : renderer(renderer), sceneManager(sceneManager)
{    font = TTF_OpenFont("../assets/Helvetica.ttc", 32);
    if (!font) {
        SDL_Log("StartScene: Failed to load font: %s", TTF_GetError());
        return;
    }

    SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, "Press Enter to Start", white);
    if (!surface) {
        SDL_Log("StartScene: Failed to create surface: %s", TTF_GetError());
        return;
    }

    messageTexture = SDL_CreateTextureFromSurface(renderer, surface);
    messageRect = {250, 250, surface->w, surface->h};
    SDL_FreeSurface(surface);
}

void StartScene::handleEvent(const SDL_Event &e) {
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
        SDL_Log("StartScene: Switching to PlayScene");
        sceneManager->setScene(std::make_unique<PlayScene>(renderer));

    }
}

void StartScene::update(float) {
    // Nothing needed here
}

void StartScene::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
    SDL_RenderClear(renderer);

    if (messageTexture) {
        SDL_RenderCopy(renderer, messageTexture, nullptr, &messageRect);
    }
}

StartScene::~StartScene() {
    SDL_Log("StartScene destructor");

    if (messageTexture) {
        SDL_DestroyTexture(messageTexture);
        messageTexture = nullptr;
    }

    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
    SDL_Log("StartScene Deconstructed.");
}