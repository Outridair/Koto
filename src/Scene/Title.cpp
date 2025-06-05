//
// Created by David Rynearson on 04.06.25.
//

#include "../../includes/Scene/Title.hpp"

Title::Title(SDL_Renderer* renderer, SceneManager* sceneManager)
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

void Title::handleEvent(const SDL_Event &e) {
    if (!sceneManager) {
        SDL_Log("ERROR: sceneManager is null in TitleScene!");
        return;
    }
    if (!renderer) {
        SDL_Log("ERROR: renderer is null in TitleScene!");
        return;
    }
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
        SDL_Log("StartScene: Switching to Level");
        sceneManager->setScene(std::make_unique<Level>(renderer, sceneManager, 1));
        SDL_Log("TitleScene: setScene returned (should be in Level now).");
    }
}

void Title::update(float) {
    // Nothing needed here
}

void Title::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
    SDL_RenderClear(renderer);

    if (messageTexture) {
        SDL_RenderCopy(renderer, messageTexture, nullptr, &messageRect);
    }
}

Title::~Title() {
    SDL_Log("Title destructor");

    if (messageTexture) {
        SDL_DestroyTexture(messageTexture);
        messageTexture = nullptr;
    }

    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
    SDL_Log("Title Deconstructed.");
}