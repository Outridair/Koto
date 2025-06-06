//
// Created by David Rynearson on 02.06.25.
//

#include "../includes/Player.hpp"

void Player::init(SDL_Renderer* renderer, int x, int y) {
    SDL_Log("Player::init - start");
    rect = { x, y, FRAME_WIDTH, FRAME_HEIGHT };
    SDL_Surface* surface = IMG_Load("../assets/player_sheet.png");
    if (!surface) {
        SDL_Log("Failed to load sprite: %s", IMG_GetError());
        return;
    }

    spriteSheet = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Log("Player::init - success");
}

void Player::handleInput(const SDL_Event &e) {
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                velX = -200;
                facing = Direction::Left;
                break;
            case SDLK_RIGHT:
                velX = 200;
                facing = Direction::Right;
                break;
            case SDLK_SPACE:
                if (jumpCount < 3) {
                    float jumpVelocity = baseJumpVelosity;
                    float currentTime = static_cast<float>(SDL_GetTicks()) / 1000.0f;


                    if (jumpCount == 1 && currentTime - lastJumpTime <= jumpBoostWindow)
                        jumpVelocity *= 1.2f;
                    else if (jumpCount == 2 && (currentTime - lastJumpTime) <= jumpBoostWindow)
                        jumpVelocity *= 1.4f;
                    else if (jumpCount > 0)
                        jumpVelocity = baseJumpVelosity;

                    velY = jumpVelocity;
                    lastJumpTime = currentTime;
                    jumpCount++;
                    isJumping = true;
                }
                break;
            default:
                break;
        }
    } else if (e.type == SDL_KEYUP) {
        if ((e.key.keysym.sym == SDLK_LEFT && velX < 0) ||
            (e.key.keysym.sym == SDLK_RIGHT && velX > 0)) {
            velX = 0;
            }
    }
}

void Player::update(float deltaTime, const std::vector<std::unique_ptr<Tile> > &tiles, const std::vector<std::unique_ptr<Enemy>>& enemies) {
    velY += 800 * deltaTime;

    rect.x += static_cast<int>(velX * deltaTime);
    rect.y += static_cast<int>(velY * deltaTime);

    for (const auto& tile : tiles) {
        SDL_Rect tRect = tile->getRect();
        if (velY > 0 && SDL_HasIntersection(&rect, &tRect)) {
            rect.y = tRect.y - rect.h;
            velY = 0;
            isJumping = false;
            jumpCount = 0;
        }
    }

    // Animate only if moving
    if (velX != 0) {
        frameTimer += deltaTime;
        if (frameTimer >= frameDelay) {
            frameTimer = 0;
            currentFrame = (currentFrame + 1) % 4;
        }
    } else {
        currentFrame = 0;
    }
    for (const auto& enemy : enemies) {
        SDL_Rect enemyRect = enemy->getRect();

        if (SDL_HasIntersection(&rect, &enemyRect)) {
            // Reset position or handle defeat
            rect.x = 100;
            rect.y = 500;
            velX = 0;
            velY = 0;
            isJumping = false;
            SDL_Log("Hit an enemy! Resetting position.");
        }
    }
}

void Player::render(SDL_Renderer *renderer, const SDL_Rect& camera) const {
    int row = (facing == Direction::Right) ? 10 : 8;

    SDL_Rect srcRect = {
        currentFrame * FRAME_WIDTH,
        row * FRAME_HEIGHT,
        FRAME_WIDTH,
        FRAME_HEIGHT
    };

    SDL_Rect destRect = {
        rect.x - camera.x,
        rect.y - camera.y,
        static_cast<int>(FRAME_WIDTH * scale),
        static_cast<int>(FRAME_HEIGHT * scale)
    };

    SDL_RenderCopy(renderer, spriteSheet, &srcRect, &destRect);
}

void Player::cleanup() {
    if (spriteSheet) {
        SDL_DestroyTexture(spriteSheet);
        spriteSheet = nullptr;
    }
}

