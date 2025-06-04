//
// Created by David Rynearson on 02.06.25.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <SDL.h>
#include "Player.hpp"
#include "Level.hpp"
#include "Camera.hpp"

enum class GameState {
    StartScreen,
    Playing,
    Paused,
    GameOver
};

class Game {
public:
    bool init(const char* title, int width, int height);
    void run();
    void cleanup();
    ~Game() { cleanup(); }
private:
    GameState state = GameState::StartScreen;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isRunning = false;

    Player player;
    Level level;
    Camera* camera = nullptr;

    void processInput();
    void update(float deltaTime);
    void render();
};



#endif //GAME_HPP
