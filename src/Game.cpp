//
// Created by David Rynearson on 02.06.25.
//

#include "../includes/Game.hpp"

#include <iostream>

#include "../includes/Scene/Title.hpp"

bool Game::init(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;

    if (TTF_Init() != 0) return false;

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) return false;

    font = TTF_OpenFont("../assets/Helvetica.ttc", 24);
    if (!font) return false;

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!window) return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) return false;

    sceneManager.setScene(std::make_unique<Title>(renderer, &sceneManager));
    SDL_Log("Scene set.");

    isRunning = true;
    return true;
}

void Game::run() {
    Uint32 lastTime = SDL_GetTicks();

    while (isRunning) {
        Uint32 currentTime = SDL_GetTicks();
        deltaTime = static_cast<float>(currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        processInput();
        sceneManager.update(deltaTime);

        render();

        SDL_Delay(16); // optional ~60 FPS cap
    }
}

void Game::processInput() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) isRunning = false;
        sceneManager.handleEvent(e);
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
    SDL_RenderClear(renderer);

    sceneManager.render(renderer);

    SDL_RenderPresent(renderer);
}

void Game::cleanup() const {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    TTF_Quit();

    SDL_Quit();
}
