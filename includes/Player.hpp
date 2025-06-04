//
// Created by David Rynearson on 02.06.25.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "SDL.h"
#include <vector>
#include <memory>
#include "Tile.hpp"
#include <SDL_image.h>

#include "Enemy.hpp"

const int FRAME_WIDTH = 32;
const int FRAME_HEIGHT = 32;
const int SPRITE_COLS = 4;
const int SPRITE_ROWS = 13;

enum class Direction { Right, Left };

inline float scale = 2.0f;

class Player {
public:
    void init(SDL_Renderer* renderer, int x, int y);
    void handleInput(const SDL_Event& e);
    void update(float deltaTime,
                const std::vector<std::unique_ptr<Tile>>& tiles,
                const std::vector<std::unique_ptr<Enemy>>& enemies);
    void render(SDL_Renderer* renderer, const SDL_Rect& camera) const;
    void cleanup();
    int jumpCount = 0;
    float lastJumpTime = 0.0f;
    float jumpBoostWindow = 0.2f;
    float baseJumpVelosity = -400.0f; //Currently "Triple Jump is without landing" TODO fix.
    int getX() const { return rect.x; }
    int getY() const { return rect.y; }
    int getWidth() const { return rect.w; }
    int getHeight() const { return rect.h; }

private:
    SDL_Rect rect;
    float velX = 0;
    float velY = 0;
    bool isJumping = false;

    SDL_Texture* spriteSheet = nullptr;

    Direction facing = Direction::Right;
    int currentFrame = 0;
    float frameTimer = 0.0f;
    float frameDelay = 0.1f;
};



#endif //PLAYER_HPP
