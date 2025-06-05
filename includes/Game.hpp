//
// Created by David Rynearson on 02.06.25.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <SDL.h>
#include "Player.hpp"
#include "Camera.hpp"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <memory>
#include "Scene/SceneBase.hpp"
#include "SceneManager.hpp"
#include "Scene/Level.hpp"

class Game {
public:
    bool init(const char *title, int width, int height);
    void run();
    void cleanup() const;

private:
    SceneManager sceneManager;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    TTF_Font* font = nullptr;
    bool isRunning = false;
    float deltaTime = 0.0f;

    void processInput();
    void render();
};



#endif //GAME_HPP
