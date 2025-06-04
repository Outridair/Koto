//
// Created by David Rynearson on 02.06.25.
//

#include "../includes/Game.hpp"
#include "../includes/Camera.hpp"

#include <iostream>

bool Game::init(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    isRunning = window && renderer;

    level.init();
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        SDL_Log("Failed to init SDL_image: %s", IMG_GetError());
        return false;
    }
    camera = new Camera(800, 600, 3200, 600);
    player.init(renderer, 100, 500);
    state = GameState::Playing;

    return isRunning;
}

void Game::run() {
    Uint32 lastTime = SDL_GetTicks();

    while (isRunning) {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        processInput();
        update(deltaTime);
        render();

        SDL_Delay(16); // ~60 FPS
    }
}

void Game::processInput() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) isRunning = false;
        switch (state) {
            case GameState::StartScreen:
                break;
            case GameState::Playing:
                player.handleInput(e);
                break;
            case GameState::Paused:
                break;
            case GameState::GameOver:
                break;

        }

    }
}

void Game::update(float deltaTime) {
    player.update(deltaTime, level.getTiles(),  level.getEnemies());
    camera->update(player.getX(), player.getY());

    // Manually construct the player's collision rect
    SDL_Rect playerRect = {
        player.getX(),
        player.getY(),
        player.getWidth(),  // You'll need to add this
        player.getHeight()  // And this
    };
    SDL_Rect goalRect = level.getGoal()->getRect();

    if (SDL_HasIntersection(&playerRect, &goalRect)) {
        SDL_Log("Goal reached! You win!");
        state = GameState::GameOver; // or another custom win state
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
    SDL_RenderClear(renderer);

    switch (state) {
        case GameState::StartScreen:
            break;
        case GameState::Playing: {
            SDL_Rect camView = camera->getView();
            level.render(renderer, camView);
            player.render(renderer, camView);
            break;
        }
        case GameState::Paused:
            break;
        case GameState::GameOver:
            break;
    }

    SDL_RenderPresent(renderer);
}

void Game::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();

    player.cleanup();
    if (camera) {
        delete camera;
        camera = nullptr;
    }

    SDL_Quit();
}
