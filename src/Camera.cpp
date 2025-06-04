//
// Created by David Rynearson on 04.06.25.
//

#include "../includes/Camera.hpp"

Camera::Camera(int screenWidth, int screenHeight, int levelW, int levelH)
    : levelWidth(levelW), levelHeight(levelH) {
    view = {0, 0, screenWidth, screenHeight};
}

void Camera::update(int playerX, int playerY) {
    // Center camera on player
    view.x = playerX - view.w / 2;
    view.y = playerY - view.h / 2;

    // Clamp within level bounds
    if (view.x < 0) view.x = 0;
    if (view.y < 0) view.y = 0;
    if (view.x > levelWidth - view.w) view.x = levelWidth - view.w;
    if (view.y > levelHeight - view.h) view.y = levelHeight - view.h;
}

const SDL_Rect& Camera::getView() const {
    return view;
}
