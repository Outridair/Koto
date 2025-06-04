#include "../includes/Enemy.hpp"

Enemy::Enemy(int x, int y, int w, int h) {
    SDL_Log("Enemy::constructor at x=%d y=%d", x, y);
    rect = {x, y, w, h};
}

void Enemy::update(float deltaTime) {
    // Could add idle animation or basic logic
}

void Enemy::render(SDL_Renderer* renderer, const SDL_Rect& camera) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
    SDL_Rect drawRect = {
        rect.x - camera.x,
        rect.y - camera.y,
        rect.w,
        rect.h
    };
    SDL_RenderFillRect(renderer, &drawRect);
}

SDL_Rect Enemy::getRect() const {
    return rect;
}
